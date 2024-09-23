/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

class Float_ : public IOperand {
    public:
        explicit Float_(const std::string &value);
        virtual std::string toString() const override;
        virtual eOperandType getType() const override;

        virtual IOperand *operator+(const IOperand &value) const override;
        virtual IOperand *operator-(const IOperand &value) const override;
        virtual IOperand *operator*(const IOperand &value) const override;
        virtual IOperand *operator/(const IOperand &value) const override;
        virtual IOperand *operator%(const IOperand &value) const override;

        virtual ~Float_() override;
    private:
        double valeur;
};

#endif /* !FLOAT_HPP_ */
