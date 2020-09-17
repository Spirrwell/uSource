/**
 * 
 * string.h
 * 
 * Custom string class
 * 
 */ 
#pragma once

#include <stddef.h>
#include <stdint.h>
#include "common.h"

class EXPORT String;
class EXPORT StringView;

class EXPORT String
{
private:
	char* m_string;
	unsigned long long m_length;

	friend class StringView;
public:
	String();
	String(const String& other);
	String(String&& other);
	String(const char* str);

	~String();

	const char* c_str() const;

	size_t length() const;

	bool empty() const;

	/* Equality tests */
	bool equals(const String& other) const;
	bool equals(const StringView& other) const;
	bool equals(const char* other) const;

	/* Inequality tests */
	bool iequals(const String& other) const;
	bool iequals(const StringView& other) const;
	bool iequals(const char* other) const;

	bool contains(const char* subst) const;
	bool contains(const String& subst) const;
	bool contains(const StringView& subst) const;

	bool startswith(const char* subst) const;
	bool startswith(const String& subst) const;
	bool startswith(const StringView& subst) const;

	bool endswith(const char* subst) const;
	bool endswith(const String& subst) const;
	bool endswith(const StringView& subst) const;

	void to_lower();
	void to_upper();
	size_t replace(char c, char n, size_t max = 0);

	String substr(size_t start, size_t end);

	operator const char*() const { return m_string; };
	explicit operator char*() { return m_string; };
	char operator[](size_t i) const;
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator=(const char* other);
	String& operator=(const StringView& other);

	bool operator==(const String& other) const;
	bool operator==(const char* other) const;
	bool operator==(const StringView& other);
	bool operator!=(const String& other) const;
	bool operator!=(const char* other) const;
	bool operator!=(const StringView& other) const;

	explicit operator class StringView() const;

	class StringView string_view() const;
};

/* Simply maintains a pointer to a character string */
/* Useful if you don't want to be doing malloc and stuff constantly */
class StringView
{
private:
	const char* m_string;
	unsigned long long m_length;

	friend class String;
public:
	StringView(const StringView& other);
	StringView(const StringView&& other) noexcept;
	StringView(const char* str);
	StringView(const String& str);

	~StringView();

	bool empty() const;

	/* Returns a modifyable string */
	String to_string() const;
	String copy() const;

	/* Returns a pointer to the internal string buffer */
	const char* string() const;
	const char* c_str() const;

	/* returns the length */
	size_t length() const { return m_length; }

	/* Equality tests */
	bool equals(const StringView& other) const;
	bool equals(const String& other) const;
	bool equals(const char* other) const;

	/* Case insensitive equality tests */
	bool iequals(const StringView& other) const;
	bool iequals(const String& other) const;
	bool iequals(const char* other) const;

	bool contains(const char* subst) const;
	bool contains(const String& subst) const;
	bool contains(const StringView& subst) const;

	bool startswith(const char* subst) const;
	bool startswith(const String& subst) const;
	bool startswith(const StringView& subst) const;

	bool endswith(const char* subst) const;
	bool endswith(const String& subst) const;
	bool endswith(const StringView& subst) const;

	/* Casting operators */
	explicit operator const char*() const { return m_string; }
	explicit operator String() const;

	char operator[](size_t i) const;

	/* Assignment operators */
	StringView& operator=(const String& other);
	StringView& operator=(const StringView& other);
	StringView& operator=(StringView&& other) noexcept;

	/* Equality tests */
	bool operator==(const StringView& other) const;
	bool operator==(const String& other) const;
	bool operator==(const char* other) const;
	bool operator!=(const StringView& other) const;
	bool operator!=(const String& other) const;
	bool operator!=(const char* other) const;
};