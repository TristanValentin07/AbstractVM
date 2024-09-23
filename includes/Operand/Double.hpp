/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

class Double_ : public IOperand {
    public:
        explicit Double_(const std::string &value);
        virtual std::string toString() const override;
        virtual eOperandType getType() const override;

        virtual IOperand *operator+(const IOperand &value) const override;
        virtual IOperand *operator-(const IOperand &value) const override;
        virtual IOperand *operator*(const IOperand &value) const override;
        virtual IOperand *operator/(const IOperand &value) const override;
        virtual IOperand *operator%(const IOperand &value) const override;

        virtual ~Double_() override;
    private:
        double valeur;
};

#endif /* !DOUBLE_HPP_ */
