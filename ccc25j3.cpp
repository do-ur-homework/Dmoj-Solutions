#include <iostream>
#include <string>
#include <cctype>

int codeamount = 0;
std::string s;
int main(){

	std::cin >> codeamount ;

	for( int i = 0 ; i < codeamount ; i++ ){

		std::cin >> s ;

		int sum = 0 ;

		for( char c : s ){
			if( std::isupper( (unsigned char)c ) ){
				std::cout << c ;
			}
		}

		int n = s.size() ;

		for( int j = 0 ; j < n ; j++ ){

			if( std::isdigit( (unsigned char)s[j] ) ){

				int num = 0 ;

				while( j < n && std::isdigit( (unsigned char)s[j] ) ){
					num = num * 10 + ( s[j] - '0' ) ;
					j++ ;
				}

				sum += num ;
				j-- ;
			}

			else if( s[j] == '-' && j + 1 < n && std::isdigit( (unsigned char)s[j+1] ) ){

				int num = 0 ;
				j++ ;

				while( j < n && std::isdigit( (unsigned char)s[j] ) ){
					num = num * 10 + ( s[j] - '0' ) ;
					j++ ;
				}

				sum -= num ;
				j-- ;
			}

		}

		std::cout << sum << "\n" ;
	}

	return 0 ;
}