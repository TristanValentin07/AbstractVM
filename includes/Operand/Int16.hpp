/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

class Int16_ : public IOperand {
    public:
        explicit Int16_(const std::string &value);
        virtual std::string toString() const override;
        virtual eOperandType getType() const override;

        virtual IOperand *operator+(const IOperand &value) const override;
        virtual IOperand *operator-(const IOperand &value) const override;
        virtual IOperand *operator*(const IOperand &value) const override;
        virtual IOperand *operator/(const IOperand &value) const override;
        virtual IOperand *operator%(const IOperand &value) const override;

        virtual ~Int16_() override;
    private:
        int16_t valeur;
};

#endif /* !INT16_HPP_ */
