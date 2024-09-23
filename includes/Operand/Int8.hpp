/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "Factory.hpp"
#include "IOperand.hpp"

class Int8_ : public IOperand {
    public:
        explicit Int8_(const std::string &value);
        virtual std::string toString() const override;
        virtual eOperandType getType() const override;

        virtual IOperand *operator+(const IOperand &value) const override;
        virtual IOperand *operator-(const IOperand &value) const override;
        virtual IOperand *operator*(const IOperand &value) const override;
        virtual IOperand *operator/(const IOperand &value) const override;
        virtual IOperand *operator%(const IOperand &value) const override;

        virtual ~Int8_() override;
    private:
        int8_t valeur;
};

#endif /* !INT8_HPP_ */
