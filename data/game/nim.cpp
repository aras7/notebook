bool game_of_nim(vector<int> stacks) {
    int answer = 0;
    
    for(int i = 0; i < stacks.size(); i++)
        answer ^= stacks[i];
    
    return answer != 0;
}