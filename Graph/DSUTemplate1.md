## DSU Template - 1

    class DSU{
    private:
        vector<int>parent;
    public:
        vector<int>size;
    
        DSU(int n){
            parent.resize(n + 1);
            size.resize(n + 1, 1);
    
            for(int i = 1; i<= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
    
        int findParent(int x){
            if(parent[x] == x) return x;
            return parent[x] = findParent(parent[x]);
        }
    
        void Union(int x, int y){
            int Px = findParent(x);
            int Py = findParent(y);
    
            if(size[Py] > size[Px]) swap(Px, Py);
            size[Px] += size[Py];
    
            parent[Py] = Px;
        }
    
        int sizeOfset(int x){
            return size[x];
        }
    };
