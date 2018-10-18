std::string bingo(std::vector<std::pair<std::string, int>> ticket, int win)
{
  int count = 0;
  for(int i=0;i<ticket.size();i++) {
    if(ticket[i].first.find(char(ticket[i].second)) != std::string::npos)count++;
  }
  return (count>=win)?"Winner!":"Loser!";
}
