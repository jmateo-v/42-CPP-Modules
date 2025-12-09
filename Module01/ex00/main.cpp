#include "Zombie.hpp"

int main(void)
{
    Zombie * heapZombie = newZombie("Heapward");
    delete heapZombie;

    randomChump("Johny J. Stackilla");
}