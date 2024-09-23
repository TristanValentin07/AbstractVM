/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Command_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Build.hpp"
#include "Vm.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Exception.hpp"
#include "Parser.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Type.hpp"
#include <cmath>

void redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(build_tests, push_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	cr_assert_not(vm.pile.empty(), "La pile ne devrait pas être vide après un push.");
	cr_assert_eq(vm.pile.back()->toString(), "42", "La valeur au sommet de la pile devrait être '42'.");
}

Test(build_tests, pop_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	build.pop();
	cr_assert(vm.pile.empty(), "La pile devrait être vide après un pop.");
}

Test(build_tests, clear_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	build.push(eOperandType::Int16, "84");
	build.clear();
	cr_assert(vm.pile.empty(), "La pile devrait être vide après un clear.");
}

Test(build_tests, dup_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	build.dup();
	cr_assert_eq(vm.pile.size(), 2, "La pile devrait contenir deux éléments après un dup.");
	cr_assert_eq(vm.pile.back()->toString(), "42", "La valeur dupliquée au sommet de la pile devrait être '42'.");
}

Test(build_tests, swap_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	build.push(eOperandType::Int16, "84");
	build.swap();
	cr_assert_eq(vm.pile.back()->toString(), "42", "Après un swap, la valeur au sommet de la pile devrait être '42'.");
	cr_assert_eq(vm.pile[vm.pile.size() - 2]->toString(), "84", "Après un swap, la nouvelle valeur en deuxième position devrait être '84'.");
}

Test(build_tests, assert_test_failure, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	cr_expect_throw(build.assert(eOperandType::Int16, "42"), Exception, "Assert devrait lancer une exception si le type ne correspond pas.");
}

Test(build_tests, load_store_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "42");
	build.store(eOperandType::Int8, "0");
	build.clear();
	build.load(eOperandType::Int8, "0");
	cr_assert_not(vm.pile.empty(), "La pile ne devrait pas être vide après un load.");
	cr_assert_eq(vm.pile.back()->toString(), "42", "La valeur chargée dans la pile devrait être '42'.");
}

Test(build_tests, add_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "20");
	build.push(eOperandType::Int8, "22");
	build.add();
	cr_assert_eq(vm.pile.back()->toString(), "42", "Le résultat de l'addition devrait être '42'.");
}

Test(build_tests, sub_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "62");
	build.push(eOperandType::Int8, "20");
	build.sub();
	cr_assert_eq(vm.pile.back()->toString(), "42", "Le résultat de la soustraction devrait être '42'.");
}

Test(build_tests, mult_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "21");
	build.push(eOperandType::Int8, "2");
	build.mult();
	cr_assert_eq(vm.pile.back()->toString(), "42", "Le résultat de la multiplication devrait être '42'.");
}

Test(build_tests, div_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "84");
	build.push(eOperandType::Int8, "2");
	build.div();
	cr_assert_eq(vm.pile.back()->toString(), "42", "Le résultatdevrait être '42'.");
}

Test(build_tests, mod_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "85");
	build.push(eOperandType::Int8, "43");
	build.mod();
	cr_assert_eq(vm.pile.back()->toString(), "42", "Le résultat du modulo devrait être '42'.");
}

Test(build_tests, print_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, std::to_string('A'));
	build.print();
	cr_assert_stdout_eq_str("A\n", "La fonction print devrait afficher 'A'.");
}

Test(build_tests, exit_test, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.exit();
	cr_assert(build.is_exit(), "La fonction exit devrait mettre à jour l'état pour indiquer la sortie.");
}

Test(build_tests, get_found_type_test, .init=redirect_all_stdout)
{
    Vm vm;
    Build build(vm);
    eOperandType type = eOperandType::Int8;
    cr_assert_eq(build.get_found_type(type), "int8", "Le type Int8 devrait être retourné sous forme de chaîne de caractères.");
}




Test(operand_test_Int8_add, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "10");
	build.push(eOperandType::Int8, "10");
	build.add();
	cr_assert_eq(vm.pile.back()->toString(), "20", "Le résultat devrait être '20'.");
}

Test(operand_test_Int8_sub, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "10");
	build.push(eOperandType::Int8, "10");
	build.sub();
	cr_assert_eq(vm.pile.back()->toString(), "0", "Le résultat devrait être '0'.");
}

Test(operand_test_Int8_mul, test3, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "10");
	build.push(eOperandType::Int8, "10");
	build.mult();
	cr_assert_eq(vm.pile.back()->toString(), "100", "Le résultat devrait être '100'.");
}

Test(operand_test_Int8_div, test4, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "10");
	build.push(eOperandType::Int8, "2");
	build.div();
	cr_assert_eq(vm.pile.back()->toString(), "5", "Le résultat devrait être '5'.");
}

Test(operand_test_Int8_mod, test5, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int8, "10");
	build.push(eOperandType::Int8, "2");
	build.mod();
	cr_assert_eq(vm.pile.back()->toString(), "0", "Le résultat devrait être '0'.");
}

Test(operand_test_Int16_add, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int16, "10");
	build.push(eOperandType::Int16, "2");
	build.add();
	cr_assert_eq(vm.pile.back()->toString(), "12", "Le résultat devrait être '12'.");
}

Test(operand_test_Int16_sub, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int16, "10");
	build.push(eOperandType::Int16, "2");
	build.sub();
	cr_assert_eq(vm.pile.back()->toString(), "8", "Le résultat devrait être '8'.");
}

Test(operand_test_Int16_mult, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int16, "10");
	build.push(eOperandType::Int16, "2");
	build.mult();
	cr_assert_eq(vm.pile.back()->toString(), "20", "Le résultat devrait être '20'.");
}

Test(operand_test_Int16_div, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int16, "10");
	build.push(eOperandType::Int16, "2");
	build.div();
	cr_assert_eq(vm.pile.back()->toString(), "5", "Le résultat devrait être '5'.");
}

Test(operand_test_Int16_mod, test5, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int16, "10");
	build.push(eOperandType::Int16, "2");
	build.mod();
	cr_assert_eq(vm.pile.back()->toString(), "0", "Le résultat devrait être '0'.");
}

Test(operand_test_Int32_add, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int32, "10");
	build.push(eOperandType::Int32, "2");
	build.add();
	cr_assert_eq(vm.pile.back()->toString(), "12", "Le résultat devrait être '12'.");
}

Test(operand_test_Int32_sub, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int32, "10");
	build.push(eOperandType::Int32, "2");
	build.sub();
	cr_assert_eq(vm.pile.back()->toString(), "8", "Le résultat devrait être '8'.");
}

Test(operand_test_Int32_mult, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int32, "10");
	build.push(eOperandType::Int32, "2");
	build.mult();
	cr_assert_eq(vm.pile.back()->toString(), "20", "Le résultat devrait être '20'.");
}

Test(operand_test_Int32_div, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int32, "10");
	build.push(eOperandType::Int32, "2");
	build.div();
	cr_assert_eq(vm.pile.back()->toString(), "5", "Le résultat devrait être '5'.");
}

Test(operand_test_Int32_mod, test5, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Int32, "10");
	build.push(eOperandType::Int32, "2");
	build.mod();
	cr_assert_eq(vm.pile.back()->toString(), "0", "Le résultat devrait être '0'.");
}

Test(operand_test_float_add, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Float, "10.2");
	build.push(eOperandType::Float, "2.4");
	build.add();
	cr_assert_eq(vm.pile.back()->toString(), "12.6", "Le résultat devrait être '12.6'.");
}

Test(operand_test_Float_sub, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Float, "10.2");
	build.push(eOperandType::Float, "2.4");
	build.sub();
	cr_assert_eq(vm.pile.back()->toString(), "7.8", "Le résultat devrait être '7.8'.");
}

Test(operand_test_Float_mult, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Float, "10.2");
	build.push(eOperandType::Float, "2.4");
	build.mult();
	cr_assert_eq(vm.pile.back()->toString(), "24.48", "Le résultat devrait être '24.48'.");
}

Test(operand_test_Float_div, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Float, "10.2");
	build.push(eOperandType::Float, "2.4");
	build.div();
	cr_assert_eq(vm.pile.back()->toString(), "4.25", "Le résultat devrait être '4.25'.");
}

Test(operand_test_Double_add, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Double, "10.2");
	build.push(eOperandType::Double, "2.4");
	build.add();
	cr_assert_eq(vm.pile.back()->toString(), "12.6", "Le résultat devrait être '12.6'.");
}

Test(operand_test_Double_sub, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Double, "10.2");
	build.push(eOperandType::Double, "2.4");
	build.sub();
	cr_assert_eq(vm.pile.back()->toString(), "7.8", "Le résultat devrait être '7.8'.");
}

Test(operand_test_Double_mult, test2, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Double, "10.2");
	build.push(eOperandType::Double, "2.4");
	build.mult();
	cr_assert_eq(vm.pile.back()->toString(), "24.48", "Le résultat devrait être '24.48'.");
}

Test(operand_test_Double_div, test1, .init=redirect_all_stdout)
{
	Vm vm;
	Build build(vm);
	build.push(eOperandType::Double, "10.2");
	build.push(eOperandType::Double, "2.4");
	build.div();
	cr_assert_eq(vm.pile.back()->toString(), "4.25", "Le résultat devrait être '4.25'.");
}
