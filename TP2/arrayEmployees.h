struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

void showEmployee(Employee x);

int initEmployees(Employee list[], int len);
void printEmployees(Employee list[],int len);
void sortEmployeesById(Employee list[], int len,int order);
void sortEmployeesByLastNameSector(Employee list[], int len,int order);
void sortEmployeesByName(Employee list[], int len,int order);
int findFreePlace(Employee list[],int len);
int findEmployeeById(Employee list[],int len,int id);
int addEmployee(Employee employees[],int len,int id);
int removeEmployee(Employee employees[], int len);
int modifyEmployee(Employee employees[], int len);
Employee newEmployee(int id,char name[],char lastName[],float salary,int sector );

int hardcodeoEmployees(Employee employees[],int len,int cant);





