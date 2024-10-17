// URL - https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


/*

THe above is a constant window, how do you know, it gave the size as fixed and the condition here is to get
the first negative number in the window.


    - Now in this question we need give the first negative element in the given window size


    - Now say we have 

            - {-8, 2, 3, -6, 10} , k= 2 

            - Now say I am keep tracking of the only first elements of the window then it won't work,
              because if the window has consecutive -ve elements, then we might ignore the other -ve elements
              while moving the window

            - {-8, -6, 3, -6, 10} 

            - Do a dry run, you will know why you have to store the elements in a queue

            - This is the reason why we use a queue and see what are the -ve numbers that we have seen and process
              accordingly

*/

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
                                                 
                                                 
        
        queue<long long int> q;
        
        vector<long long> v;
        
        
        long long int i=0,j=0;
        
        while(j<N){
            
            if(A[j]<0){
                q.push(A[j]);
            }
            
            if((j-i+1)<k) 
                j++;
            else if( (j-i+1) == k){
                
                if(q.empty()){
                    v.push_back(0);
                }
                else{
                    v.push_back(q.front()); // Proeccessed the window
                    
                    if(A[i]==q.front())
                        q.pop();
                }
                i++; // Mpve the start of the window
                j++; // Move the end of the window, in the next iteration this element will get added so need not explicitly add this
            }
        }
        return v;
 }



