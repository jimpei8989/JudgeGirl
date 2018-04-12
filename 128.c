int in( int i, int j, int map[ 100 ][ 100 ] ){
    if( i < 0 || j < 0 ) return 0;
    if( i > 99 || j > 99 ) return 0;
    return map[ i ][ j ];
}

void intersection(int map[100][100], int result[4]){
    int dx[ 4 ] = { 1, 0, -1, 0 };
    int dy[ 4 ] = { 0, 1, 0, -1 };

    for( int i = 0; i < 4; i++ ) result[ i ] = 0;

    for( int i = 0; i < 100; i++ ){
        for( int j = 0; j < 100; j++ ){
            int tp = 0;
            for( int k = 0; k < 4; k++ ){
                tp += in( i + dx[ k ], j + dy[ k ], map );
            }
            if( in( i, j, map ) == 0 ) continue;
            if( tp == 4 ) result[ 0 ] ++;
            if( tp == 3 ) result[ 1 ] ++;
            if( tp == 1 ) result[ 3 ] ++;
            if( tp == 2 ){
                if( in( i + dx[ 0 ], j + dy[ 0 ], map ) != in( i + dx[ 2 ], j + dy[ 2 ], map ) ){
                    result[ 2 ] ++;
                }
            }
        }
    }
}