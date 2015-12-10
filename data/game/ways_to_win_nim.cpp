int ways_to_win_game_of_nim(vector<int> stacks) {
    int nim = 0;
   
    for(int i = 0; i < stacks.size(); i++)
        nim ^= stacks[i];
    
    int answer = 0;
    
    for(int i = 0; i < stacks.size(); i++)
        if((nim ^ stacks[i]) < stacks[i])
            answer++;
        
     return answer;
}