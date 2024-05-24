    struct Node{
        bool isEnd = false;
        map<int, Node*>mp;
    
        bool isEndOfNumber(){
            return isEnd;
        }
    
        void setEndOfNumber(){
            isEnd = true;
        }
    
    
        void addChild(int bit){
            mp[bit] = new Node();
        }
    
        Node *goToChild(int bit){
            return mp[bit];
        }
    
        bool isEmptyNode(){
            return (size(mp) == 0);
        }
    
        bool hasChild(int bit){
            if(mp.find(bit) != mp.end()) return true;
            return false;
        }
    
    };
    
    struct Trie{
        Node * root;
        Trie(){
            root = new Node();
        }
    
        void insertNumber(int num){
            Node *currNode = root;
    
            for(int i = 31; i >= 0; i--){
                int bit = num & (1 << i);
    
                if(!currNode -> hasChild(bit)){
                    currNode -> addChild(bit);
                }
                currNode = currNode -> goToChild(bit);
            }
    
            currNode -> setEndOfNumber();
        }
    
        bool searchNumber(int num){
            Node *currNode = root;
    
            for(int i = 31; i >= 0; i--){
                int bit = num & (1 << i);
    
                if(!currNode -> hasChild(bit)){
                    return false;
                }
                currNode = currNode -> goToChild(bit);
            }
    
            if(currNode -> isEndOfNumber()) return true;
            return false;
        }
    };
    
    void Solve(){
    
        vector<int>arr = {2, 8, 13, 56, 22, 34};
    
        Trie trie = Trie();
    
        for(auto x : arr){
            trie.insertNumber(x);
        }
    
        int ans = trie.searchNumber(3);
        cout << ans << lb;
    }
