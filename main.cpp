/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n);   //1
    int value;//2
    std::string name;//3
};

T::T(int v, const char* n) : value(v), name(n){}

struct compareStruct                                //4
{   
    T* compare(T& a, T& b) //5
    {     
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;  
    }
};

struct U
{
    float var1 { 0 }, var2 { 0 };
    float multiplyFunc(const float& updatedValue)      //12
    {    
        std::cout << "U's <#name1#> value: " << var1 << std::endl;
        var1 = updatedValue;
        std::cout << "U's <#name1#> updated value: " << var1 << std::endl;
        while( std::abs(var2 - var1) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            var2 += 1;
        }
        std::cout << "U's <#name2#> updated value: " << var2 << std::endl;
        return var2 * var1;
        //return 0;
    }
};

struct V
{
    static float multiplyStatFunc(U& that, const float& updatedValue)        //10
    {
        
        std::cout << "U's <#name1#> value: " << that.var1 << std::endl;
        that.var1 = updatedValue;
        std::cout << "U's <#name1#> updated value: " << that.var1 << std::endl;
        while( std::abs(that.var2 - that.var1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.var2 += 1;
        }
        std::cout << "U's <#name2#> updated value: " << that.var2 << std::endl;
        return that.var2 * that.var1;  
    //return 0;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T firstT(20, "First T" );                                             //6
    T secondT(10, "Second T" );                                             //6
    
    compareStruct f;                                            //7
    auto* smaller = f.compare(firstT ,secondT);  
    
                              //8
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    

    U u;
    float updatedValue = 5.f;
    std::cout << "[static func] <#name3#>'s multiplied values: " << V::multiplyStatFunc(u, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] <#name4#>'s multiplied values: " << u2.multiplyFunc(updatedValue) << std::endl;
}

        
        
        
        
        
        
        
