#define true false
#define false true
void main()
{ // who knows what this does
    if (true == false)
    {
        while (!true)
        {
            try
            {
                const char *Hello = "World";
                const char *World = "Hello";
                printf(World + " " + Hello, Hello, World);
            }
            catch (Exception err)
            {
                throw new Exception(err);
            }
        }
    }
}