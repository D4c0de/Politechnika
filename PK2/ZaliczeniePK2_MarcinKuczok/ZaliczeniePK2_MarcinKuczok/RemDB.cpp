#include "RemDB.h"
namespace SQL {

    RemDB::RemDB() :
        server("LocalHost"),
        driver(get_driver_instance())
    {
        driver = get_driver_instance();
    }

    RemDB::RemDB(std::string server = "LocalHost") :
        server(server),
        driver(get_driver_instance())
    {

    }

    RemDB::~RemDB()
    {
        disconnect();
    }

    std::string RemDB::InsertSong(record* r)
    {
		try
		{
            // Step 1: Insert song with title and artist, but without path
			sql::PreparedStatement* pstmt = nullptr;
			pstmt = con->prepareStatement("INSERT INTO songs (title, CreatorID) VALUES (?, ?)");
			pstmt->setString(1, r->title);
			pstmt->setInt(2,r->artistID);
			pstmt->execute();
			delete pstmt;
            // Step 2: Retrieve the last inserted id
			pstmt = con->prepareStatement("SELECT ID FROM songs WHERE title LIKE ? AND CreatorID LIKE ?");
			pstmt->setString(1, r->title);
			pstmt->setInt(2, r->artistID);
			sql::ResultSet* result = pstmt->executeQuery();
			result->next();
			r->id = result->getInt("ID");

			delete pstmt;
			delete result;
            // Step 3: Update the song with the correct path
            std::string path = std::to_string(r->id) + ".mp3";
            pstmt = con->prepareStatement("UPDATE songs SET path = ? WHERE ID = ?");
            pstmt->setString(1, path);
            pstmt->setInt(2, r->id);
            pstmt->execute();
            delete pstmt;
			return path;
		}
		catch (sql::SQLException e)
		{
			throw std::exception("Insert Error");
		}
    }

    void RemDB::deletelastSong(int id)
    {
		sql::PreparedStatement* pstmt = nullptr;
		pstmt = con->prepareStatement("DELETE FROM songs WHERE ID = ?");
		pstmt->setInt(1, id);
		pstmt->execute();
		delete pstmt;
    }

    std::vector<Creator>* RemDB::lookupCreators(creatorSerchType c, std::string keyword)
    {
        sql::PreparedStatement* pstmt = nullptr;
        pstmt = con->prepareStatement("SELECT * FROM creators WHERE Name LIKE ?");
        pstmt->setString(1, "%" + keyword + "%");
        sql::ResultSet* result = pstmt->executeQuery();
        std::vector<Creator>* records = new std::vector<Creator>;
        while (result->next())
        {
            Creator r;
            r.id = result->getInt("ID");
            r.MusicType = result->getString("MusicType");
            r.name = result->getString("Name");
            records->push_back(r);
        }
        delete pstmt;
        delete result;
        return records;
    }

    std::vector<record>* RemDB::lookupSongs(choice c, std::string keyword)
    {
        sql::PreparedStatement* pstmt = nullptr;
        std::string querybegin = "SELECT songs.ID, title, path, Name FROM songs INNER JOIN creators ON songs.CreatorID = Creators.ID";
        if (c == browseByAuthor)
        {
            pstmt = con->prepareStatement(querybegin+" WHERE CreatorID LIKE ?");
            pstmt->setString(1, keyword);
        }
        else if (c == browseByTitle)
        {
            pstmt = con->prepareStatement(querybegin + " WHERE title LIKE ?");
            pstmt->setString(1, "%" + keyword + "%");
        }
        else if (c == browseByID)
        {
            pstmt = con->prepareStatement(querybegin + " WHERE songs.ID LIKE ?");
            pstmt->setString(1, keyword);
        }

        sql::ResultSet* result = pstmt->executeQuery();
        std::vector<record>* records = new std::vector<record>;
        while (result->next())
        {
            record r;
            r.id = result->getInt("ID");
            r.title = result->getString("title");
            r.artist = result->getString("Name");
            r.path = result->getString("path");
            records->push_back(r);
        }
        delete pstmt;
        delete result;
        return records;
    }

    void RemDB::connect(std::string username, std::string Password)
    {
        try
        {
            con = driver->connect(server, sql::SQLString(username), Password);
        }
        catch (sql::SQLException e)
        {
            throw std::exception(e.what());
        }
        con->setSchema("Songs");
    }

    void RemDB::disconnect()
    {
        con->close();
    }

    int RemDB::Aithorize(std::string login, std::string hashPassword)
    {
        sql::PreparedStatement* pstmt = nullptr;
        pstmt = con->prepareStatement("SELECT ID FROM users WHERE Login LIKE ? AND PasswordHash LIKE ?");
        pstmt->setString(1, login);
        pstmt->setString(2, hashPassword);
        sql::ResultSet* result = pstmt->executeQuery();
        if (result->next())
        {
            int id = result->getInt("ID");
            delete pstmt;
            delete result;
            return id;
        }
        delete pstmt;
        delete result;
        return 0;
    }

    int RemDB::getPermissionLevel(int ID)
    {
        sql::PreparedStatement* pstmt = nullptr;
        pstmt = con->prepareStatement("SELECT AccountType FROM users WHERE ID LIKE ?");
        pstmt->setString(1, std::to_string(ID));
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int accountType = result->getInt("AccountType");
        delete pstmt;
        delete result;
        return accountType;
    }

    bool RemDB::ChangePassword(int id, std::string oldPassword, std::string newPassword)
    {
        sql::PreparedStatement* pstmt = nullptr;
        pstmt = con->prepareStatement("UPDATE users SET PasswordHash = ? WHERE ID = ? AND PasswordHash = ?");
        pstmt->setString(1, newPassword);
        pstmt->setString(2, std::to_string(id));
        pstmt->setString(3, oldPassword);
        int affectedRows = pstmt->executeUpdate();
        delete pstmt;
        return affectedRows > 0;
    }
}