int GetParent(vector<int>&par, int node){
    if(par[node] == node){
        return node;
    }

    int p = GetParent(par, par[node]);
    par[node] = p;
    return p;
}

void UnionBySize(vector<int>&par, vector<int>&sizeOf, int nodeA, int nodeB){

    int p1 = GetParent(par, nodeA);
    int p2 = GetParent(par, nodeB);

    if(p1 == p2) return;

    if(sizeOf[p2] < sizeOf[p1]){
        sizeOf[p1] = sizeOf[p1] + sizeOf[p2];
        sizeOf[p2] = -1;
        par[p2] = p1;
    }else{
        sizeOf[p2] = sizeOf[p2] + sizeOf[p1];
        sizeOf[p1] = -1;
        par[p1] = p2;
    }
}
