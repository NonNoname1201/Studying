#include <iostream>
#include "src/student.h"
#include "src/Animal.h"
#include "src/Cat.h"
#include "src/Dog.h"

int howManyProtectedAnimals(Animal *animals[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (animals[i]->getProtectedAnimal())
        {
            counter++;
        }
    }
    return counter;
}

void howManyTrackerDogs(Dog *dogs[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (dogs[i]->getSkillLevel(1) < dogs[i]->getSkillLevel(2))
        {
            dogs[i]->info();
        }
    }
}

void howManyCats(Cat *cats[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        for (int j = 0; j < 5; j++)
        {
            counter += cats[i]->getMice(j);
        }
        cout << "Kot " << cats[i]->getName() << " upolowal " << counter << " myszy" << endl;
    }
}

int main()
{
    //    Student a[3] = {Student("Jan", "Kowalski", 20, "123456"), Student("Adam", "Nowak", 21, "654321"),
    //                    Student("Anna", "Kowalska", 22, "111111")};
    //
    //    Student *b = new Student[3];`
    //
    //    Student *c[3];
    //
    //    Student **d = new Student *[3];

    Animal *animals[5];
    animals[0] = new Cat(5, new int[5]{1, 2, 3, 4, 5});
    animals[1] = new Cat(3, new int[5]{1, 2, 3, 4, 5});
    animals[2] = new Dog("Owczarek", 5, 3);
    animals[3] = new Dog("Husky", 5, 3);
    animals[4] = new Dog("Buldog", 5, 3);

    cout << "Chronione: " << howManyProtectedAnimals(animals, 5) << endl;

    Dog *dogs[3];
    dogs[0] = new Dog("Owczarek", 5, 5);
    dogs[1] = new Dog("Husky", 5, 3);
    dogs[2] = new Dog("Buldog", 5, 4);

    howManyTrackerDogs(dogs, 3);

    Cat *cats[2];
    cats[0] = new Cat(5, new int[5]{1, 2, 3, 4, 5});
    cats[0]->setName("Murek");
    cats[1] = new Cat(3, new int[5]{1, 2, 3, 4, 5});
    cats[1]->setName("Filemon-1");

    howManyCats(cats, 2);

    return 0;
}
