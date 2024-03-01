#pragma once
#include "expression.hh"


class expressionFigure: public Expression{
    public:
    expressionFigure(FigurePtr fig){
        _figure = fig;
    };
    ~expressionFigure() = default;
    FigurePtr calculer2();
    double calculer(const Contexte& contexte) const override { return 1; };
    private:
    FigurePtr _figure;
};