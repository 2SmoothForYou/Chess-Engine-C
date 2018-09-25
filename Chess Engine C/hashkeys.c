//
//  hashkeys.c
//  Chess Engine C
//
//  Created by Jaime Ricart on 9/25/18.
//  Copyright © 2018 Jaime Ricart. All rights reserved.
//

#include "defs.h"

U64 GeneratePosKey(const S_BOARD *pos){
    
    int sq = 0;
    U64 finalKey = 0;
    int piece = EMPTY;
    
    for(sq = 0; sq < BRD_SQR_NUM; ++sq) {
        piece = pos->pieces[sq];
        if(piece!=NO_SQ && piece!=EMPTY) {
            ASSERT(piece>=wP && piece<=bK);
            finalKey ^= PieceKeys[piece][sq];
        }
    }
    
    if(pos->side == WHITE) {
        finalKey ^= SideKey;
    }
    
    if(pos->enPas != NO_SQ) {
        ASSERT(pos->enPas>=0 && pos->enPas<BRD_SQR_NUM);
        finalKey ^= PieceKeys[EMPTY][pos->enPas];
    }
    
    ASSERT(pos->castlePerm>=0 && pos->castlePerm<=15);
    
    finalKey ^= CastleKeys[pos->castlePerm];
    
    return finalKey;
    
}
