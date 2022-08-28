//preprocess output : g++ -E enum_to_string.cpp > enum_to_string.E
//compile: g++  enum_to_string.cpp 

#include <stdio.h>

//debug macro, keep it defined or undefine
//#define DEBUG 
#undef DEBUG

#ifndef DEBUG
        #define DECL_ENUM_ELEMENT( element ) element
        #define BEGIN_ENUM( ENUM_NAME ) typedef enum
        #define END_ENUM( ENUM_NAME )  ENUM_NAME;
#else
        #define DECL_ENUM_ELEMENT( element ) #element
        #define BEGIN_ENUM( ENUM_NAME ) const char* gs_##ENUM_NAME [] =
        #define END_ENUM( ENUM_NAME ); \
                                int gs_##ENUM_NAME##size = sizeof(gs_##ENUM_NAME)/sizeof(gs_##ENUM_NAME[0]); \
                                const char* MatchEnumToString##ENUM_NAME(int  index) { \
                                if (index > (gs_##ENUM_NAME##size - 1) || index < 0) \
                                { \
                                       return "ERR: invalid"; \
                                }  \
                                else \
                                       return gs_##ENUM_NAME [index]; \
                                }
#endif                            

BEGIN_ENUM(Days)
{
    DECL_ENUM_ELEMENT(sunday),
    DECL_ENUM_ELEMENT(monday),
    DECL_ENUM_ELEMENT(tuesday),
    DECL_ENUM_ELEMENT(wednesday),
    DECL_ENUM_ELEMENT(thursday),
    DECL_ENUM_ELEMENT(friday),
    DECL_ENUM_ELEMENT(saturday)
}
END_ENUM(Days)

BEGIN_ENUM(fruit)
{
    DECL_ENUM_ELEMENT(apple),
    DECL_ENUM_ELEMENT(orange),
    DECL_ENUM_ELEMENT(mango)
}
END_ENUM(fruit)

void match_etos( int index )
{
#ifdef DEBUG
            printf("Day is %s ,", MatchEnumToStringDays(index) );
            printf("Fruit is %s\n", MatchEnumToStringfruit(index) );
#else
            printf("disabled match_etos, index: %d\n", index);
#endif                      
}

int main()
{
        match_etos(0);
        match_etos(1);
        match_etos(2);
        match_etos(3);
        match_etos(4);
        match_etos(5);
        match_etos(6);
        match_etos(-43);
#ifdef DEBUG        
        printf("gs_Dayssize %d, gs_fruitsize %d\n", gs_Dayssize, gs_fruitsize);
#endif
        return 0;
}
