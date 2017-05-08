//
// Created by kubas1129 on 26.04.17.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H


class Shape {
public:
    virtual void Draw() const = 0;
};

class Circle : public Shape
{
public:
    virtual void Draw() const override;
};

class Triangle : public Shape
{
public:
    virtual void Draw() const override;
};

class Square : public Shape
{
public:
    virtual void Draw() const override;
};


#endif //JIMP_EXERCISES_SHAPE_H
