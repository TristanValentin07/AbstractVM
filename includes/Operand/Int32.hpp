/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

class Int32_ : public IOperand {
    public:
        explicit Int32_(const std::string &value);
        virtual std::string toString() const override;
        virtual eOperandType getType() const override;

        virtual IOperand *operator+(const IOperand &value) const override;
        virtual IOperand *operator-(const IOperand &value) const override;
        virtual IOperand *operator*(const IOperand &value) const override;
        virtual IOperand *operator/(const IOperand &value) const override;
        virtual IOperand *operator%(const IOperand &value) const override;

        virtual ~Int32_() override;
    private:
        int32_t valeur;
};
#endif /* !INT32_HPP_ */
