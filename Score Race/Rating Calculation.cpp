#include <iostream>
#include <math.h>
using namespace std ;

struct point
{
	int score ;
	double rating_delta ;
} ;

int main()
{
	cout << "Please type your score and difficulty by order:" << endl ;
	int score = 0 , case_id = 0 ;
	double difficulty = 0 ;
	cin >> score >> difficulty ;
	if ( score <= 0 || score > 1010000 )
	{
		case_id = -1 ;
	}
	point list[8] = { { 0 , -100 } , { 500000 , -5 } , { 900000 , -1 } , { 980000 , 1 } ,
	{ 1000000 , 2 } , { 1004000 , 2.4 } , { 1008000 , 3.4 } , { 1010000 , 3.6 } } ;
	if ( case_id == -1 )
	{
		cout << "ERROR!" << endl ;
		return 0 ;
	}
	for ( int i = 0 ; i < 8 ; i++ )
	{
		if ( list[i].score <= score && score <= list[i+1].score )
		{
			case_id = i ;
			break ;
		}
	}
	double delta = 0 , delta_percent = 0 ;//delta = final_rating - rating
	delta_percent = ( ( double ) ( score - list[case_id].score ) ) / ( list[case_id+1].score - list[case_id].score ) ;
	delta = list[case_id].rating_delta + delta_percent * ( list[case_id+1].rating_delta - list[case_id].rating_delta ) ;
	double final_rating = 0 ;
	final_rating = difficulty + delta ;
	if ( final_rating < 0 )
	{
		final_rating = 0 ;
	}
	cout << final_rating << endl ;
	system ( " pause " ) ;
    return 0 ;
}
