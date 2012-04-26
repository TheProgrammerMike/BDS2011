/* file: strutils/strutils.h
   author: Christoph Bauer
   date: 7.6.00
   license: GPL

*/

#ifndef __STRUTILS_H__
#define __STRUTILS_H__

#include <string>
#include <string.h>

class StrUtils
{
 public:
  static std::string getFileExt( std::string filename );

  struct equstr
    {
      bool operator()( const char *s1, const char * s2 )
      { return strcmp( s1, s2 ) == 0; }
  };

  template<class String>
  struct hash_string
  {
    size_t operator()( const String & s ) const
    {
      size_t t=0;
      for( unsigned int i=0; i < s.length(); i++ )
	t=7*t+s[i];
      return t;
    }
  };
  
};
#endif  
