class Stree{
    vi seg,lazy;
public:
    Stree(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }

    void build(int index,int low,int right,vi& arr){
        if(low==right){
            seg[index] = arr[low];
            return;
        }

        int mid = (right+low)/2;

        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,right,arr);
        seg[index] = seg[2*index+1]+seg[2*index+2];

    }

    void update(int index,int low,int right,int l,int r,int val){
        //update whenever possible
        if(lazy[index]!=0){

            seg[index]+=(right-low+1)*lazy[index];

            if(low!=right){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
         }

            lazy[index] = 0;
        }

        //no overlap
        if(right<l || low>r){
            return;
        }

        //complete overlap

        if(low>=l && right<=r){
            seg[index] += (right-low+1)*val;

            if(low!=right){
                lazy[2*index+1] += val;
                lazy[2*index+2] += val;
            }
            return;
        }

        //partial overlap
        int mid = (right+low)/2;
        update(2*index+1,low,mid,l,r,val);
        update(2*index+2,mid+1,right,l,r,val);
        seg[index] = seg[2*index+1]+seg[2*index+2];


    }

    int query(int index,int low,int right,int l ,int r){

        if(lazy[index]!=0){

            seg[index]+=(right-low+1)*lazy[index];

            if(low!=right){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
         }

            lazy[index] = 0;
        }
        //no overlap
        if(low>r || right<l){
            return 0;
        }

        //complete overlap
        if(low>=l && right<=r){
            return seg[index];
        }

        //partial overlap
        int mid = (right+low)/2;
        int left = query(2*index+1,low,mid,l,r);
        int high = query(2*index+2,mid+1,right,l,r);
        return left+high;

    }

};
