/*
Description:
Some people are standing in a row in a park. There are trees between them which cannot be moved. Your task is to rearrange the people by their heights in a non-descending order without moving the trees. People can be very tall!

Example

For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

URL: https://app.codesignal.com/arcade/intro/level-3/D6qmdBL2NYz49XHwM/description

*/

std::vector<int> sortByHeight(std::vector<int> a) {
    std::vector<int> res;
    std::vector<int> pos;
    for(int i=0;i<a.size();i++) {
        if(a[i]==-1){pos.push_back(i);}
        else res.push_back(a[i]);
    }
    std::sort(res.begin(), res.end());
    for(auto i:pos) {
        res.insert(res.begin()+i, -1);
    }
    
    return res;
}
