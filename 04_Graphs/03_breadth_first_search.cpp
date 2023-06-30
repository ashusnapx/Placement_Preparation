/* also called level wise traversal */

vector<int> bfs(int number_of_vertices, vector<int> &adj[])
{
    /* step - 1 : ek visited array create krlo, pr kyu? kyunki visited array tumhe ek hi node baar baar n use krlo usse bachayega, wrna infinite loop mei fase reh jaoge */
    int visited[number_of_vertices] = {0};

    /* ab dekho tumhe pehla element khud se hi queue mei push krna pdega + visited array me 1 krna pdega kyunki pehla element daaloge tabhi n queue non empty rhega, wrna while(!q.empty()) wala condition kabhi bhi while loop mei enter nhi krne dega */
    visited[0] = 1;

    /* abhi tk mei maine ek array create kiya hai visited array ke naam se aur uske pehle element mtlb visited[0] ko maine 1 kr diya hai. */

    /* ab main ek queue create krunga, pr kyu? kyunki queue FIFO principle pe kaam krta hai, jiska mtlb yeh hai ki jo element pehle jayega whi pehle niklega, aur hmen waise bhi pehla element nikaal kr uske baaki neighbours ko bhi queue mei daalna hai, taaki woh sab + unke neighbours traverse ho payein */
    queue<int> q;

    /* ab halaki maine pehle hi visited ke 0th index ko 1 kr diya tha, ab main pehla value jo ki root of the whole tree hai, usey push krunga */
    q.push(0);

    /* yeh pehle se mentioned tha ki 0 based indexed tree hai, iss liye maine 0 ko visited + push kr diya queue mein */

    /* ab main ek result vector bnaunga, jiska kaam hi yhi hai answers store kare */
    vector<int> result;

    /* ab main condition lgao ki jab tk queue khaali n ho tab tk chalate rho while loop ko */
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        int size = q.size();

        for(auto it: adj[node])
        {
            if(visited[it] == 0)
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return result;
}