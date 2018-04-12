#include <stdio.h>

typedef struct {
    char n[20];
    int i;
    char p[10];
    float g[4];
    int b[ 3 ];
} Student;


void output( FILE *fout, Student tmp ){
	fprintf( fout, "<tr>\n" );
	fprintf( fout, "<td>%s</td>\n", tmp.n );
	fprintf( fout, "<td>%d</td>\n", tmp.i );
	fprintf( fout, "<td>%s</td>\n", tmp.p );
	fprintf( fout, "<td>%f, %f, %f, %f</td>\n", tmp.g[ 0 ], tmp.g[ 1 ], tmp.g[ 2 ], tmp.g[ 3 ] );
	fprintf( fout, "<td>%d, %d, %d</td>\n", tmp.b[ 0 ], tmp.b[ 1 ], tmp.b[ 2 ] );
	fprintf( fout, "</tr>\n");
}

int main(){
	char ipt[ 128 ];
	char opt[ 128 ];
	scanf("%s%s", ipt, opt );
	FILE *fin = fopen( ipt, "rb" );
	FILE *fout = fopen( opt, "w" );
	Student tmp;
	fprintf( fout, "<table border=\"1\">\n" );
	fprintf( fout, "<tbody>\n" );
	while( fread( &tmp, sizeof( Student ), 1, fin ) == 1 ){
		output( fout, tmp );
	}
	fprintf( fout, "</tbody>\n");
	fprintf( fout, "</table>\n");
}