MAX, MIN = float('inf'), float('inf') 
  
# Returns optimal value for current player  
#(Initially called for root and maximizer)  
def minimax(depth, maximizingPlayer, player1, player2, ef, alpha, beta):
	if depth == 0:
		return ef()

	if maximizingPlayer:  
    	best = MIN 
        temp = list(moves.items())
        for key, pos in temp:
            next_pos = player1.pos[0] + pos[0], player1.pos[1] + pos[1]
            if board.is_free(next_pos[0], next_pos[1]):
                player1.update(next_pos[0], next_pos[1])
	            val = minimax(depth - 1, False, player1, player2, alpha, beta)  
	            best = max(best, val)
	            player1.undo_move()
            alpha = max(alpha, best)  
            # Alpha Beta Pruning  
            if beta <= alpha:  
                break
        return best
    else: 
        best = MAX 
        temp = list(moves.items())
        for key, pos in temp:
            next_pos = player2.pos[0] + pos[0], player2.pos[1] + pos[1]
            if board.is_free(next_pos[0], next_pos[1]):
                player2.update(next_pos[0], next_pos[1])
	            val = minimax(depth - 1, True, player1, player2, alpha, beta)  
            	best = min(best, val)
            	player2.undo_move()
            beta = min(beta, best)  
            # Alpha Beta Pruning  
            if beta <= alpha:  
                break 
        return best  