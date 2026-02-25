#include <iostream>
#include "student.h"
#include "functii.h"

int main()
{
    student s1, s2;

    s1.setname("Alex");
    s1.setmate(10.0);
    s1.seteng(8.0);
    s1.setist(6.5);

    s2.setname("Sabin");
    s2.setmate(9.5);
    s2.seteng(9.5);
    s2.setist(7.0);

    std::cout << "Student 1: " << s1.getname() << ' ' << s1.getmate() << ' ' << s1.geteng() << ' ' << s1.getist() << ' ' << "media " << s1.medie();
    std::cout << std::endl;
    std::cout << "Student 2: " << s2.getname() << ' ' << s2.getmate() << ' ' << s2.geteng() << ' ' << s2.getist() << ' ' << "media " << s2.medie();
    std::cout << std::endl;

    return 0;
}
