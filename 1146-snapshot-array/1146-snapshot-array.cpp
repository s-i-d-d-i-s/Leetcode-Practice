class SnapshotArray {
public:
    int snapId=0;
    unordered_map<int,unordered_map<int,int>> snapshot;
    
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        snapshot[snapId][index]=val;
    }
    
    int snap() {
        snapId++;
        snapshot[snapId]=snapshot[snapId-1];
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        return snapshot[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */