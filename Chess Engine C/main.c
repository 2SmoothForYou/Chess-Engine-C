//
//  main.c
//  Chess Engine C
//
//  Created by Jaime Ricart on 9/24/18.
//  Copyright © 2018 Jaime Ricart. All rights reserved.
//

#include <stdio.h>
#include "defs.h"

int main(int argc, const char * argv[]) {
    
    AllInit();
    
    U64 playBitBoard = 0ULL;
    
    printf("Start:\n");
    PrintBitBoard(playBitBoard);
    
    playBitBoard |= (1ULL << SQ64(D2));
    
    printf("D2 Added:\n");
    PrintBitBoard(playBitBoard);
    
    return 0;
    
}
