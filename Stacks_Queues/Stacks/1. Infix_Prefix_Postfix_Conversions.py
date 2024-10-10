# URL - https://www.youtube.com/watch?v=4pIc9UBHJtk&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=3


# Watch the video for all the possible Infix, Prefix and Postfix conversions




#Infix to Postfix conversion - MAIN conversion

class Solution:
    
    #Function to convert an infix expression to a postfix expression.
    def InfixtoPostfix(self, exp):
        #code here
        
        n=len(exp)
        i=0
        priority={'^' : 3, '*': 2, '/':2, '+':1, '-':1 ,'(':-1,')':-1 }
        
        postfix="" # for the expression
         
        st=[] # for the operators
        
        while(i<n):
            
            if((exp[i]>='a' and exp[i]<='z') or (exp[i]>='A' and exp[i]<='Z') or (exp[i]>='0' and exp[i]<='9')): # for operand
                postfix+=str(exp[i])
            else:
                if(len(st)==0 or exp[i]=='('):
                    st.append(exp[i])
                elif(exp[i]==')'):
                    while(len(st)!=0 and st[-1]!='('):
                        postfix+=str(st[-1])
                        st.pop()
                    st.pop() # pop the open bracket
                else:
                    if(st[-1]=='('):
                        st.append(exp[i])
                    else:
                        if(priority[exp[i]]>priority[st[-1]]):
                            st.append(exp[i]) #Push if operator is grater than top
                        else:
                            while(len(st)!=0 and (priority[exp[i]]<=priority[st[-1]])):
                                postfix+=str(st[-1])
                                st.pop()
                            st.append(exp[i])
                
            i+=1
        
        while(len(st)!=0):
            postfix+=str(st[-1])
            st.pop()
            
        return postfix            




#Infix to Prefix conversion - MAIN conversion

'''

Here given the Infix exp - reverse the expression

and do the normal thing like the Postfix and then reverse the result which is the Prefix.

Small caveats is how to pop the operators with the precedance

'''





''' Postfix to Infix conversion  NOTE : Always remember if it is a conversion from Postfix, traverse from forward

    Given is a valid Postfix expression

    Here when we encounter a operator we take the TOP TWO things in the stack, say t1 and t2 and make it " ( t2 operator t1 ) " and put this new string into the stack.


    Now Remember while evaluation we do the same but we compute the above and push the result into the stack, it's the same thing we are doing but with variables
'''
class Solution:
    def postToInfix(self, postfix):
        # Code here
        
        n=len(postfix)
        
        i=0
        st=[] #stack
         
        while(i<n):
            
            if((postfix[i]>='a' and postfix[i]<='z') or (postfix[i]>='A' and postfix[i]<='Z')): # for operand
                st.append(str(postfix[i]))
            else: # for operator
                
                op1 = st[-1]
                st.pop()
                
                op2 = st[-1]
                st.pop()
                
                st.append("(" + op2 + str(postfix[i]) +op1 + ")")
                
            i+=1
        
        if(len(st)==1):
            return st[-1]
        return ""



''' Postfix to Prefix conversion

    Given is a valid Postfix expression

    Here when we encounter a operator we take the TOP TWO things in the stack, say t1 and t2 and make it " ( operator t2 t1 ) " and put this new string into the stack (brackets upto you ).


    Now Remember while evaluation we do the same but we compute the above and push the result into the stack, it's the same thing we are doing but with variables
'''


class Solution:
    def postToPre(self, postfix):
        # Code here
        
        n=len(postfix)
        
        i=0
        st=[] #stack
         
        while(i<n):
            
            if((postfix[i]>='a' and postfix[i]<='z') or (postfix[i]>='A' and postfix[i]<='Z')): # for operand
                st.append(str(postfix[i]))
            else: # for operator
                
                op1 = st[-1]
                st.pop()
                
                op2 = st[-1]
                st.pop()
                
                st.append(str(postfix[i])+ op2 +op1)
                
            i+=1
        
        if(len(st)==1):
            return st[-1]
        return ""



''' Prefix to Infix conversion  NOTE : Always remember if it is a conversion from Prefix we traverse from the last (or reverse the array traverse from front and reverse the result expression)

    Given is a valid Prefix expression

    Here when we encounter a operator we take the TOP TWO things in the stack, say t1 and t2 and make it " ( t2 operator t1 ) " and put this new string into the stack (brackets is better ).


    Now Remember while evaluation we do the same but we compute the above and push the result into the stack, it's the same thing we are doing but with variables
'''

class Solution:
    def preToInfix(self, prefix):
        # Code here
        
        n=len(prefix)
        
        i=n-1
        st=[] #stack
         
        while(i>=0):
            
            if((prefix[i]>='a' and prefix[i]<='z') or (prefix[i]>='A' and prefix[i]<='Z')): # for operand
                st.append(str(prefix[i]))
            else: # for operator
                
                op1 = st[-1]
                st.pop()
                
                op2 = st[-1]
                st.pop()
                
                st.append("("+ op1 + str(prefix[i])+ op2 + ")")
                
            i-=1
        
        if(len(st)==1):
            return st[-1]
        return ""



''' Prefix to Postfix conversion  NOTE : Always remember if it is a conversion from Prefix we traverse from the last (or reverse the array traverse from front and reverse the result expression)

    Given is a valid Prefix expression

    Here when we encounter a operator we take the TOP TWO things in the stack, say t1 and t2 and make it " ( t2 t1 operator) " and put this new string into the stack (brackets upto you ).


    Now Remember while evaluation we do the same but we compute the above and push the result into the stack, it's the same thing we are doing but with variables
'''


class Solution:
    def preToPost(self, prefix):
        # Code here
        
        n=len(prefix)
        
        i=n-1
        st=[] #stack
         
        while(i>=0):
            
            if((prefix[i]>='a' and prefix[i]<='z') or (prefix[i]>='A' and prefix[i]<='Z')): # for operand
                st.append(str(prefix[i]))
            else: # for operator
                
                op1 = st[-1]
                st.pop()
                
                op2 = st[-1]
                st.pop()
                
                st.append(op1 + op2 + str(prefix[i]))
                
            i-=1
        
        if(len(st)==1):
            return st[-1]
        return ""
        

