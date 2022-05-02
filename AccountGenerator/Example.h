#pragma once
#include "Database/Model.h"

class User final : public AccountDatabase::Model
{
public:
	User() = default;
	User(AccountDatabase::ID _id, std::string _email, std::string _username, std::string _password)
		: Model{ _id }, m_Email(std::move(_email)), m_Username(std::move(_username)), m_Password(std::move(_password))
	{
	}
	~User() override = default;

	[[nodiscard]] const std::string& GetEmail() const { return m_Email; }
	[[nodiscard]] const std::string& GetUsername() const { return m_Username; }
	[[nodiscard]] const std::string& GetPassword() const { return m_Password; }

	void FromString(AccountDatabase::ID _id, const mtk::List<std::string_view>& _contents) override
	{
		m_ID = _id;
		m_Email = _contents[0];
		m_Username = _contents[1];
		m_Password = _contents[2];
	}

	void FromString(AccountDatabase::ID _id, const mtk::List<std::string>& _contents) override
	{
		m_ID = _id;
		m_Email = _contents[0];
		m_Username = _contents[1];
		m_Password = _contents[2];
	}

	void FromString(AccountDatabase::ID _id, const mtk::List<const char*>& _contents) override
	{
		m_ID = _id;
		m_Email = _contents[0];
		m_Username = _contents[1];
		m_Password = _contents[2];
	}

	[[nodiscard]] std::string ToString() const override
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