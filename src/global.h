#ifndef GLOBAL_H
#define GLOBAL_H

class Global
{
public:
        static void GenerateLife() { life = rand() % (10 - 4 + 1) + 4; }

        static void ModifyLife(int injury) { life += injury; }

        static int CheckLife() { return life; }

protected:
    static int life;
};

#endif // GLOBAL_H
