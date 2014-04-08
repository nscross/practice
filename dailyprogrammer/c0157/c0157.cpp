
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

const char kBlankTile = '-';
const char kXTile = 'X';
const char kOTile = 'O';
const char kCRTile = '\r';
const char kNewlineTile = '\n';
const char kNumberOfRows = 3;
const char kNumberOfColumns = 3;
const char kNumberOfTilesToWin = 3;
    
bool IsValidCharacter(const char input)
{    
    bool is_valid_char = false;
    
    switch(input)
    {
        case kXTile:
        case kOTile:
        case kBlankTile:
            is_valid_char = true;
            break;
        default:
            is_valid_char = false;        
            break;
    };
    return is_valid_char;
}

bool IsReturnCharacter(const char input)
{
    bool is_valid_char = false;
    
    switch(input)
    {
        case kCRTile:
        case kNewlineTile:        
            is_valid_char = true;
            break;
        default:
            is_valid_char = false;        
            break;
    };
    return is_valid_char;
}

int CalculateWinningLocation(const char* board, const char player_tile, char* play_next_locations)
{
    int number_of_winning = 0;
    // check rows
    for(int row_ndx = 0; row_ndx < kNumberOfRows; row_ndx++)
    {
        int num_player_tiles = 0;
        int blank_tile_col = -1;        
        
        for(int col_ndx = 0; col_ndx < kNumberOfColumns; col_ndx++)
        {
            char spot = *(board+(row_ndx*kNumberOfColumns) + col_ndx);
            if (spot == player_tile)
            {
                num_player_tiles++;
            }
            else if(spot == kBlankTile)
            {
                blank_tile_col = col_ndx;
            }
            else
            {
                // can't win this row
                break;
            }            
        }
        
        if (num_player_tiles == kNumberOfTilesToWin - 1
            && blank_tile_col != -1)
        {
            *(play_next_locations+(number_of_winning*2)) = row_ndx;
            *(play_next_locations+(number_of_winning*2)+1) = blank_tile_col;            
            number_of_winning++;
        }
    }
    
    // check cols
    for(int col_ndx = 0; col_ndx < kNumberOfColumns; col_ndx++)
    {    
        int num_player_tiles = 0;
        int blank_tile_row = -1;
         
        for(int row_ndx = 0; row_ndx < kNumberOfRows; row_ndx++)
        {        
            char spot = *(board+(row_ndx*kNumberOfColumns) + col_ndx);
            if (spot == player_tile)
            {
                num_player_tiles++;
            }
            else if(spot == kBlankTile)
            {
                blank_tile_row = row_ndx;
            }
            else
            {
                // can't win this row
                break;
            }            
        }
        
        if (num_player_tiles == kNumberOfTilesToWin - 1
            && blank_tile_row != -1)
        {
            *(play_next_locations+(number_of_winning*2)) = blank_tile_row;
            *(play_next_locations+(number_of_winning*2)+1) = col_ndx;            
            number_of_winning++;
        }
    }
        
    // check diag
    int num_player_tiles = 0;
    int blank_tile_row = -1;
    int blank_tile_col = -1;
    for(int row_ndx = 0, col_ndx = 0; row_ndx < kNumberOfRows; row_ndx++, col_ndx++)
    {
        char spot = *(board+(row_ndx*kNumberOfColumns) + col_ndx);
        if (spot == player_tile)
        {
            num_player_tiles++;
        }
        else if(spot == kBlankTile)
        {
            blank_tile_row = row_ndx;
            blank_tile_col = col_ndx;
        }
        else
        {
            // can't win this row
            break;
        }   
    }
    
    if (num_player_tiles == kNumberOfTilesToWin - 1
        && blank_tile_row != -1
        && blank_tile_col != -1)
    {
        *(play_next_locations+(number_of_winning*2)) = blank_tile_row;
        *(play_next_locations+(number_of_winning*2)+1) = blank_tile_col;            
        number_of_winning++;
    } 

    num_player_tiles = 0;
    blank_tile_row = -1;
    blank_tile_col = -1;
    for(int row_ndx = 0, col_ndx = kNumberOfColumns - 1; row_ndx < kNumberOfRows; row_ndx++, col_ndx--)
    {
        char spot = *(board+(row_ndx*kNumberOfColumns) + col_ndx);
        if (spot == player_tile)
        {
            num_player_tiles++;
        }
        else if(spot == kBlankTile)
        {
            blank_tile_row = row_ndx;
            blank_tile_col = col_ndx;
        }
        else
        {
            // can't win this row
            break;
        }   
    }
    
    if (num_player_tiles == kNumberOfTilesToWin - 1
        && blank_tile_row != -1
        && blank_tile_col != -1)
    {
        *(play_next_locations+(number_of_winning*2)) = blank_tile_row;
        *(play_next_locations+(number_of_winning*2)+1) = blank_tile_col;            
        number_of_winning++;
    }        
    
      
    return number_of_winning;
}

int main (int argc, char *argv[])
{
    char board[kNumberOfRows][kNumberOfColumns];    
    char player_tile;
    char enemy_tile;
        
    // get input    
    int input_char = fgetc(stdin);
    
    if (input_char != EOF)
    {
        if (IsValidCharacter(input_char))
        {
            player_tile = input_char;            
            enemy_tile = (input_char == kXTile) ? kOTile : kXTile;            
        }
        else
        {
            printf("Error: Unexpected player character: %c.  Use X or O.\n", input_char);
            return(-1);
        }
    }
    
    int board_ndx = 0;
    char* ptr_to_board = &board[0][0];
    
    while(board_ndx < (kNumberOfRows * kNumberOfColumns))
    {           
        input_char = fgetc(stdin);
        if (input_char != EOF)
        {
            if (IsValidCharacter(input_char))
            {
                *(ptr_to_board+board_ndx) = input_char;                
                board_ndx++;                 
            }
            else if (!IsReturnCharacter(input_char))
            {
                printf("Error: Unexpected board character: %c.  Use X, O, or -.\n", input_char);
                return(-1);
            }                
        }
        else
        {
            printf("Error: Not enough board characters: Need 3x3 matrix.\n");
            return(-1);
        }
    }   
        
    // calculate if there's a winning move
    int number_of_wins = 0;
    int number_of_blocks = 0;
    char play_next_locations[5][2];
    
    number_of_wins = CalculateWinningLocation((const char*)&board[0][0],
        player_tile, (char*)&play_next_locations[0][0]);
    
    if (number_of_wins == 0)
    {        
        number_of_blocks = CalculateWinningLocation((const char*)&board[0][0],
        enemy_tile, (char*)&play_next_locations[0][0]);
    }
    
    char* play_type = NULL;
    char win_string[] = "Winning";
    char block_string[] = "Block";
    int number_of_solutions = 0;
    
    if (number_of_wins > 0)
    {       
        printf("%d winnings moves available.\n", number_of_wins);
        play_type = &win_string[0];     
        number_of_solutions = number_of_wins;        
    }
    else if(number_of_blocks > 0)
    {
        printf("%d blocking moves available.\n", number_of_blocks);
        play_type = &block_string[0];     
        number_of_solutions = number_of_blocks;                
    }
    else
    {
        printf("No Winning Move!\n");
    }
    
    for(int ndx = 0; ndx < number_of_solutions; ndx++)
    {
        printf("\n%s Move #%d\n", play_type, ndx+1);
        
        board[play_next_locations[ndx][0]][play_next_locations[ndx][1]] = player_tile;
                    
        for (int row_ndx = 0; row_ndx < kNumberOfRows; row_ndx++)
        {
            for (int col_ndx = 0; col_ndx < kNumberOfColumns; col_ndx++)
            {
                printf("%c", board[row_ndx][col_ndx]);                
            }
            printf("\n");
        }
        
        board[play_next_locations[ndx][0]][play_next_locations[ndx][1]] = kBlankTile;
    }
    
    
    return 0;    
}

