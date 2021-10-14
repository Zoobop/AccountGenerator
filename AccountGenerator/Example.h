#pragma once
#include "Database/Model.h"

class User : public AccountDatabase::Model
{
public:
	User() = default;
	User(AccountDatabase::ID _id, const std::string& _email, const std::string& _username, const std::string& _password)
		: Model{ _id }, m_Email(_email), m_Username(_username), m_Password(_password)
	{
	}

	const std::string& GetEmail() const { return m_Email; }
	const std::string& GetUsername() const { return m_Username; }
	const std::string& GetPassword() const { return m_Password; }

	virtual void FromString(AccountDatabase::ID _id, const mtk::List<std::string_view>& _contents) override
	{
		m_ID = _id;
		m_Email = _contents[0];
		m_Username = _contents[1];
		m_Password = _contents[2];
	}

	virtual void FromString(AccountDatabase::ID _id, const mtk::List<const char*>& _contents) override
	{
		m_ID = _id;
		m_Email = _contents[0];
		m_Username = _contents[1];
		m_Password = _contents[2];
	}

	virtual std::string ToString() const override
	{
		return m_Email + " " + m_Username + " " + m_Password;
	}

	friend bool operator==(const User& _left, const User& _right)
	{
		return _left.m_Email == _right.m_Email;
	}

	friend bool operator!=(const User& _left, const User& _right)
	{
		return !(_left == _right);
	}

	friend std::ostream& operator<<(std::ostream& _stream, const User& _current)
	{
		_stream << _current.m_ID << ": " << _current.m_Email << " -> " << _current.m_Username;
		return _stream;
	}

private:
	std::string m_Email;
	std::string m_Username;
	std::string m_Password;
};