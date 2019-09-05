class Solution {
public:
    double median_gen(vector<int>::iterator beg,vector<int>::iterator end){
        double med;
        int size=end-beg;
        if(size%2){
            //odd
            med=*(beg+size/2);
        }
        else{
            int mid1=*(beg+(size-1)/2);
            int mid2=*(beg+size/2);
            med=(mid1+mid2)/2.0;
        }
        return med;
    }
    double median_3(int a,int b,int c){
        double median;
        
        if(a>=b){
            if(a>=c){
                if(b>=c){
                    median=b;
                }
                else{
                    median=c;
                }
            }
            else{
                median=a;
            }
        }
        else{
            if(b>=c){
                if(a>=c){
                    median=a;
                }
                else{
                    median=c;
                }
            }
            else{
                median=b;
            }
        }
        
        return median;
        
    }
    
    double median_4(int a,int b,int c,int d){
        int maximum=max(a,max(b,max(c,d)));
        int minimum=min(a,min(b,min(c,d)));
        double median;
        cout<<"\n max "<<maximum<<" min "<<minimum<<endl;
        cout<<b<<", "<<c<<endl;
        median=(a+b+c+d-maximum-minimum)/2.0;
        cout<<median<<endl;
        return median;
    }
    
    double findMedianHelper(vector<int>::iterator nums1_b,vector<int>::iterator nums1_e,vector<int>::iterator nums2_b,vector<int>::iterator nums2_e){
        
        int n1_size=nums1_e-nums1_b;
        cout<<"n1size: "<<n1_size<<" ";
        int n2_size=nums2_e-nums2_b;
        // cout<<*nums2_e<<", "<<*nums2_b<<", "<<*(nums2_e)<<", ";
        cout<<"n2size: "<<n2_size<<"\n";
        double median;
       
        int minimum_elements=min(n1_size,n2_size);
        cout<<"minimum elements: "<<minimum_elements<<"\n";
        if(minimum_elements==0){
            cout<<"minimum elements 0\n";
            if(n1_size==1 && n2_size==0){
                cout<<"n1 size 1 n2 size 0\n";
                
                median = *nums1_b;
                return median;
            }
            if(n1_size==0 && n2_size==1){
                
                median = *nums2_b;
                return median;
            }
            if((n1_size==0 && n2_size==2)){
                cout<<"n1 size 0 n2 size 2\n";
                
                median = ( *nums2_b + *(nums2_b + 1) ) / 2.0;
                return median;
            }
            else if(n1_size==2 && n2_size==0){
                cout<<"n1 size 2 n2 size 0\n";
                
                median = ( *nums1_b + *(nums1_b + 1) ) / 2.0;
                return median;
            }
            else if(n1_size==0 && n2_size==0){
                cout<<"n1 size 0 n2 size 0\n";
                
                
                return -1;
            }
            else if(n1_size==0 && n2_size!=0){
                return median_gen(nums2_b,nums2_e);
            }
            else if(n1_size!=0 && n2_size==0){
                return median_gen(nums1_b,nums1_e);
            }
        }
        
        else if(minimum_elements==1){
            cout<<"minimum elements 1\n";
            if(n1_size==1 && n2_size==1){
                cout<<"n1 size 1 n2 size 1\n";
                
                median = ( *nums2_b + *nums1_b ) / 2.0;
                return median;
            }
            
            
            else if(n1_size==1 && n2_size%2){
                cout<<"n1 size 1 n2 size odd\n";
                
                int index_med = (n2_size ) / 2;
                int left_index = index_med - 1;
                int right_index = index_med + 1;
                
                if( *nums1_b <= *(nums2_b+left_index) ){
                    median = ( *(nums2_b+left_index) + *(nums2_b+index_med) )/2.0;
                }
                else if( *nums1_b > *(nums2_b+left_index) && *nums1_b < *(nums2_b+index_med) ){
                    median = ( *nums1_b + *(nums2_b+index_med) )/2.0;
                }
                else if( *nums1_b > *(nums2_b+index_med) && *nums1_b < *(nums2_b+right_index) ){
                     median = ( *nums1_b + *(nums2_b+index_med) )/2.0;
                }
                else if( *nums1_b > *(nums2_b+right_index) ){
                     median = ( *(nums2_b+index_med) + *(nums2_b+right_index) )/2.0;
                }
                
                return median;
            }
            
            
            else if(n1_size%2 && n2_size==1){
                cout<<"n1 size odd n2 size 1\n";
                
                int index_med = (n1_size ) / 2;
                int left_index = index_med - 1;
                int right_index = index_med + 1;
                
                if( *nums2_b <= *(nums1_b+left_index) ){
                    median = ( *(nums1_b+left_index) + *(nums1_b+index_med) )/2.0;
                }
                else if( *nums2_b > *(nums1_b+left_index) && *nums2_b < *(nums1_b+index_med) ){
                    median = ( *nums2_b + *(nums1_b+index_med) )/2.0;
                }
                else if( *nums2_b > *(nums1_b+index_med) && *nums2_b < *(nums1_b+right_index) ){
                     median = ( *nums2_b + *(nums1_b+index_med) )/2.0;
                }
                else if( *nums2_b > *(nums1_b+right_index) ){
                     median = ( *(nums1_b+index_med) + *(nums1_b+right_index) )/2.0;
                }
                
                return median;
            }
            
            else if((n1_size%2==0) && n2_size==1){
                cout<<"n1 size even n2 size 1\n";
                
                int index_med_1 = (n1_size) / 2;
                int index_med_2 = (n1_size-1) / 2;
                cout<<*(nums1_b+index_med_1)<<" "<<*(nums1_b+index_med_2)<<" "<<*nums2_b<<endl;
                return median_3(*(nums1_b+index_med_1),*(nums1_b+index_med_2),*nums2_b);
            }
            
            else if(n1_size==1 && (n2_size%2==0)){
                cout<<"n1 size 1 n2 size even\n";
                
                int index_med_1 = (n2_size ) / 2;
                int index_med_2 = (n2_size - 1) / 2;
                cout<<*(nums2_b+index_med_1)<<" "<<*(nums2_b+index_med_2)<<endl;
                return median_3(*(nums2_b+index_med_1),*(nums2_b+index_med_2),*nums1_b);
            }
        }
        
        else if(minimum_elements==2){
            cout<<"minimum elements 2\n";
            if(n1_size==2 && n2_size==2){
                cout<<"n1 size 2 n2 size 2\n";
                
                cout<<"median_4\n";
                return median_4(*(nums1_b),*(nums1_b+1),*(nums2_b),*(nums2_b+1));
            }
            
            else if(n1_size==2 && n2_size%2){
                cout<<"n1 size 2 n2 size odd\n";
                
                int index_med = (n2_size-1)/2;
                
                int left=index_med-1;
                int right=index_med+1;
                
                int b=max(*nums1_b,*(nums2_b+left));
                int c=min(*(nums1_b + 1),*(nums2_b+right));
                
                return median_3(*(nums2_b+index_med),b,c);
            }
            
            else if(n1_size%2 && n2_size==2){
                cout<<"n1 size odd n2 size 2\n";
                
                int index_med = (n1_size-1)/2;
                int left=index_med-1;
                int right=index_med+1;
                
                int b=max(*nums2_b,*(nums1_b+left));
                int c=min(*(nums2_b + 1),*(nums1_b+right));
                
                return median_3(*(nums1_b+index_med),b,c);
            }
            
            else if((n1_size%2==0) && n2_size==2){
                cout<<"n1 size even n2 size 2\n";
                
                int index_med_1 = (n1_size-1)/2;
                int index_med_2 = index_med_1 + 1;
                int before_med1 = index_med_1-1;
                int after_med2 = index_med_2 + 1;
                int c = max(*nums2_b,*(nums1_b+before_med1));
                int d = min(*(nums2_b + 1),*(nums1_b+after_med2));
                
                return median_4(*(nums1_b+index_med_1),*(nums1_b+index_med_2),c,d);
                
            }
            
            else if(n1_size==2 && (n2_size%2==0)){
                cout<<"n1 size 2 n2 size even\n";
                
                int index_med_1 = (n2_size-1)/2;
                int index_med_2 = index_med_1 + 1;
                int before_med1 = index_med_1-1;
                int after_med2 = index_med_2 + 1;
                int c = max(*nums1_b,*(nums2_b+before_med1));
                int d = min(*(nums1_b + 1),*(nums2_b+after_med2));
                
                return median_4(*(nums2_b+index_med_1),*(nums2_b+index_med_2),c,d);
                
            }
        }
        
        int med1=(n1_size-1)/2;
        cout<<"med1: "<<med1<<" ";
        int med2=(n2_size-1)/2;
        cout<<"med2: "<<med2<<"\n";

        
        if(*(nums1_b+med1)<=*(nums2_b+med2)){
            //ignore med1+n1_size-1 in nums1
            //ignore 0 to med1 in nums2
           
            return findMedianHelper(nums1_b+med1,nums1_e,nums2_b,nums2_b+med1+1);
        }
        else{
            cout<<"in arr2\n";
            return findMedianHelper(nums1_b,nums1_b+med1+1,nums2_b+med1,nums2_e);
            
        }
        
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedianHelper(nums1.begin(),nums1.end(),nums2.begin(),nums2.end());
    }
    
};