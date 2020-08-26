#include "string.h"

#include "port.h"
#include "xash3d_types.h"
#include "const.h"
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include "stdio.h"
#include "crtlib.h"
#include <string.h>
#include <stdlib.h>

String::String()
{
	this->m_length = 0;
	this->m_string = nullptr;
}

String::String(const String &other) 
{
	this->m_length = other.m_length;
	this->m_string = strdup(other.m_string);
}

String::String(String &&other) 
{
	this->m_length = other.m_length;
	this->m_string = other.m_string;
	other.m_string = nullptr;
	other.m_length = 0;
}

String::String(const char *str) 
{
	this->m_length = strlen(str);
	this->m_string = strdup(str);
}

String::~String() 
{
	if(this->m_string) free(m_string);
}

const char *String::c_str() const 
{
	return this->m_string;
}

size_t String::length() const 
{
	return this->m_length;
}

bool String::equals(const String &other) const 
{
	if(!this->m_string || !other.m_string) return false;
	return Q_strcmp(this->m_string, other.m_string) == 0;
}

bool String::equals(const char *other) const 
{
	if(!this->m_string || !other) return false;
	return Q_strcmp(other, this->m_string) == 0;
}

bool String::iequals(const String &other) const 
{
	if(!this->m_string || !other.m_string) return false;
	return Q_strcasecmp(other.m_string, this->m_string);
}

bool String::iequals(const char *other) const 
{
	if(!this->m_string || !other) return false;
	return Q_strcasecmp(other, this->m_string);
}

void String::to_lower() 
{
	if(!this->m_string) return;
	for(int i = 0; i < this->m_length; i++)
		this->m_string[i] = Q_tolower(this->m_string[i]);
}

void String::to_upper() 
{
	if(!this->m_string) return;
	for(int i = 0; i < this->m_length; i++)
		this->m_string[i] = Q_toupper(this->m_string[i]);
}

size_t String::replace(char c, char n, size_t max)
{
	if(!this->m_string) return 0;
	size_t num = 0;
	max = max > 0 ? max : SIZE_MAX;
	for(size_t i = 0; i < this->m_length && max > 0; i++)
	{
		if(this->m_string[i] == c)
		{
			this->m_string[i] = n;
			max--, num++;
		}
	}
	return num;
}

bool String::empty() const  
{
	return (!this->m_string) && (this->m_length == 0);
}

String String::substr(size_t start, size_t end) 
{
	return String();
}

char String::operator[](size_t i) const 
{
	if(i < this->m_length) return this->m_string[i];
	return 0;
}

String &String::operator=(const String &other) 
{
	if(this->m_string) free(this->m_string);
	this->m_string = strdup(other.m_string);
	this->m_length = other.m_length;
	return *this;
}

String &String::operator=(String &&other) 
{
	this->m_string = other.m_string;
	this->m_length = other.m_length;
	return *this;
}

bool String::operator==(const String &other) const 
{
	return this->equals(other);
}

bool String::operator!=(const String &other) const 
{
	return !this->equals(other);
}

String::operator StringView() const
{
	return StringView(*this);
}

StringView String::string_view() const
{
	return StringView(*this);
}

bool String::contains(const char *subst) const
{
	return Q_strstr(m_string, subst) != nullptr;
}

bool String::contains(const String &subst) const
{
	return Q_strstr(m_string, subst.m_string) != nullptr;
}

bool String::contains(const StringView &subst) const
{
	return Q_strstr(m_string, subst.m_string) != nullptr;
}

bool String::equals(const StringView &other) const
{
	return Q_strcmp(m_string, other.m_string) == 0;
}

bool String::iequals(const StringView &other) const
{
	return Q_strcasecmp(m_string, other.m_string) == 0;
}

String &String::operator=(const StringView &other)
{
	if(m_string) free(m_string);
	m_length = other.m_length;
	m_string = Q_strdup(other.m_string);
	return *this;
}

String &String::operator=(const char *other)
{
	if(m_string) free(m_string);
	m_length = strlen(other);
	m_string = Q_strdup(other);
	return *this;
}

bool String::operator!=(const char *other) const
{
	return Q_strcmp(other, m_string) != 0;
}

bool String::operator!=(const StringView &other) const
{
	return Q_strcmp(other.m_string, m_string) != 0;
}

bool String::operator==(const StringView &other)
{
	return Q_strcmp(m_string, other.m_string) == 0;
}

bool String::operator==(const char *other) const
{
	return Q_strcmp(m_string, other) == 0;
}

bool String::startswith(const char *subst) const
{
	return Q_startswith(m_string, subst);
}

bool String::startswith(const String &subst) const
{
	return Q_startswith(m_string, subst.m_string);
}

bool String::startswith(const StringView &subst) const
{
	return Q_startswith(m_string, subst.m_string);
}

bool String::endswith(const char *subst) const
{
	return Q_endswith(m_string, subst);
}

bool String::endswith(const String &subst) const
{
	return Q_endswith(m_string, subst.m_string);
}

bool String::endswith(const StringView &subst) const
{
	return Q_endswith(m_string, subst.m_string);
}


StringView::StringView(const StringView &other) :
	m_string(other.m_string),
	m_length(other.m_length)
{

}

StringView::StringView(const StringView &&other) noexcept :
	m_string(other.m_string),
	m_length(other.m_length)
{

}

StringView::StringView(const char *str) :
	m_string(str),
	m_length(Q_strlen(str))
{

}

StringView::StringView(const String &str) :
	m_string(str.m_string),
	m_length(str.m_length)
{

}

StringView::~StringView()
{
}

bool StringView::empty() const
{
	return m_string == nullptr || m_length == 0;
}

String StringView::to_string() const
{
	return String(m_string);
}

const char *StringView::string() const
{
	return m_string;
}

const char *StringView::c_str() const
{
	return m_string;
}

bool StringView::equals(const StringView &other) const
{
	return Q_strcmp(m_string, other.m_string) == 0;
}

bool StringView::equals(const String &other) const
{
	return Q_strcmp(m_string, other.m_string) == 0;
}

bool StringView::equals(const char *other) const
{
	return Q_strcmp(m_string, other) == 0;
}

bool StringView::iequals(const StringView &other) const
{
	return Q_strcasecmp(m_string, other.m_string) == 0;
}

bool StringView::iequals(const String &other) const
{
	return Q_strcasecmp(m_string, other.m_string) == 0;
}

bool StringView::iequals(const char *other) const
{
	return Q_strcasecmp(m_string, other) == 0;
}

StringView::operator String() const
{
	return String(m_string);
}

char StringView::operator[](size_t i) const
{
	if(i >= m_length) return ' ';
	return m_string[i];
}

StringView &StringView::operator=(const String &other)
{
	m_string = other.m_string;
	m_length = other.m_length;
	return *this;
}

StringView &StringView::operator=(const StringView &other)
{
	m_string = other.m_string;
	m_length = other.m_length;
	return *this;
}

StringView &StringView::operator=(StringView &&other) noexcept
{
	m_string = other.m_string;
	m_length = other.m_length;
	other.m_string = nullptr;
	other.m_length = 0;
	return *this;
}

bool StringView::operator==(const StringView &other) const
{
	return Q_strcmp(other.m_string, m_string) == 0;
}

bool StringView::operator==(const String &other) const
{
	return Q_strcmp(other.m_string, m_string) == 0;
}

bool StringView::operator==(const char *other) const
{
	return Q_strcmp(other, m_string) == 0;
}

bool StringView::operator!=(const StringView &other) const
{
	return Q_strcmp(other.m_string, m_string) != 0;
}

bool StringView::operator!=(const String &other) const
{
	return Q_strcmp(other.m_string, m_string) != 0;
}

bool StringView::operator!=(const char *other) const
{
	return Q_strcmp(other, m_string) != 0;
}

String StringView::copy() const
{
	return String(m_string);
}

bool StringView::contains(const char *subst) const
{
	return Q_strstr(m_string, subst) != nullptr;
}

bool StringView::contains(const String &subst) const
{
	return Q_strstr(m_string, subst.m_string);
}

bool StringView::contains(const StringView &subst) const
{
	return Q_strstr(m_string, subst.m_string);
}

bool StringView::startswith(const char *subst) const
{
	return Q_startswith(m_string, subst);
}

bool StringView::startswith(const String &subst) const
{
	return Q_startswith(m_string, subst.m_string);
}

bool StringView::startswith(const StringView &subst) const
{
	return Q_startswith(m_string, subst.m_string);
}

bool StringView::endswith(const char *subst) const
{
	return Q_endswith(m_string, subst);
}

bool StringView::endswith(const String &subst) const
{
	return Q_endswith(m_string, subst.m_string);
}

bool StringView::endswith(const StringView &subst) const
{
	return Q_endswith(m_string, subst.m_string);
}
