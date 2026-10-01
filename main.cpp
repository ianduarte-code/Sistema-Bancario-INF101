#include <iostream>
#include <string>

using namespace std;

int main() {

    // Aqui ficam guardados os dados das contas cadastradas
    int numeroConta[5];
    string nomeCliente[5];
    string cpf[5];
    int tipoConta[5];
    double saldo[5];
    bool contaAtiva[5];

    // Guarda quantas contas já foram cadastradas
    int contas = 0;

    int opcao;

    do {

        // Menu principal do sistema
        cout << "==============================" << endl;
        cout << "       BANCO INF101" << endl;
        cout << "==============================" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:

                // O sistema permite cadastrar no máximo 5 contas
                if (contas < 5) {

                    // Confere se o número da conta é válido
                    do {
                        cout << "Digite o numero da conta: ";
                        cin >> numeroConta[contas];

                        if (numeroConta[contas] <= 0) {
                            cout << "Numero invalido! Digite um numero maior que zero." << endl;
                        }

                    } while (numeroConta[contas] <= 0);

                    cout << "Digite o nome do cliente: ";
                    cin.ignore();
                    getline(cin, nomeCliente[contas]);

                    cout << "Digite o CPF: ";
                    cin >> cpf[contas];

                    // Confere se o tipo escolhido é 1 ou 2
                    do {
                        cout << "Digite o tipo da conta (1 - Corrente / 2 - Poupanca): ";
                        cin >> tipoConta[contas];

                        if (tipoConta[contas] != 1 && tipoConta[contas] != 2) {
                            cout << "Tipo de conta invalido! Digite 1 ou 2." << endl;
                        }

                    } while (tipoConta[contas] != 1 && tipoConta[contas] != 2);

                    // O saldo inicial não pode ser negativo
                    do {
                        cout << "Digite o saldo inicial: ";
                        cin >> saldo[contas];

                        if (saldo[contas] < 0) {
                            cout << "Saldo invalido! Digite um valor maior ou igual a zero." << endl;
                        }

                    } while (saldo[contas] < 0);

                    // Toda conta começa ativa
                    contaAtiva[contas] = true;

                    // Passa para a próxima posição dos arrays
                    contas++;

                    cout << "Conta cadastrada com sucesso!" << endl;

                } else {
                    cout << "Limite de 5 contas atingido!" << endl;
                }

                break;


            case 2:

                // Não é possível consultar se não houver nenhuma conta
                if (contas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                {
                    int numero;
                    int encontrada = -1;

                    cout << "Digite o numero da conta: ";
                    cin >> numero;

                    // Procura a conta pelo número informado
                    for (int i = 0; i < contas; i++) {
                        if (numeroConta[i] == numero) {
                            encontrada = i;
                            break;
                        }
                    }

                    if (encontrada != -1) {

                        cout << "===== DADOS DA CONTA =====" << endl;
                        cout << "Numero da conta: " << numeroConta[encontrada] << endl;
                        cout << "Nome do cliente: " << nomeCliente[encontrada] << endl;
                        cout << "CPF: " << cpf[encontrada] << endl;

                        if (tipoConta[encontrada] == 1) {
                            cout << "Tipo da conta: Corrente" << endl;
                        } else {
                            cout << "Tipo da conta: Poupanca" << endl;
                        }

                        cout << "Saldo: R$ " << saldo[encontrada] << endl;

                        if (contaAtiva[encontrada] == true) {
                            cout << "Situacao: Ativa" << endl;
                        } else {
                            cout << "Situacao: Inativa" << endl;
                        }

                    } else {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;


            case 3:

                if (contas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                {
                    int numero;
                    int encontrada = -1;

                    cout << "Digite o numero da conta: ";
                    cin >> numero;

                    // Procura a conta antes de mostrar o saldo
                    for (int i = 0; i < contas; i++) {
                        if (numeroConta[i] == numero) {
                            encontrada = i;
                            break;
                        }
                    }

                    if (encontrada != -1) {

                        // Só mostra o saldo se a conta estiver ativa
                        if (contaAtiva[encontrada] == true) {
                            cout << "Seu saldo atual e: R$ " << saldo[encontrada] << endl;
                        } else {
                            cout << "A conta esta inativa." << endl;
                        }

                    } else {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;


            case 4:

                if (contas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                {
                    int numero;
                    int encontrada = -1;

                    cout << "Digite o numero da conta: ";
                    cin >> numero;

                    // Encontra a conta que será alterada
                    for (int i = 0; i < contas; i++) {
                        if (numeroConta[i] == numero) {
                            encontrada = i;
                            break;
                        }
                    }

                    if (encontrada != -1) {

                        // Só permite alterar uma conta que esteja ativa
                        if (contaAtiva[encontrada] == true) {

                            do {
                                cout << "Digite o novo tipo da conta (1 - Corrente / 2 - Poupanca): ";
                                cin >> tipoConta[encontrada];

                                if (tipoConta[encontrada] != 1 && tipoConta[encontrada] != 2) {
                                    cout << "Tipo de conta invalido! Digite 1 ou 2." << endl;
                                }

                            } while (tipoConta[encontrada] != 1 && tipoConta[encontrada] != 2);

                            cout << "Tipo da conta alterado com sucesso!" << endl;

                        } else {
                            cout << "A conta esta inativa." << endl;
                        }

                    } else {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;


            case 5:

                if (contas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                {
                    int numero;
                    int encontrada = -1;

                    cout << "Digite o numero da conta: ";
                    cin >> numero;

                    // Procura a conta que será ativada ou desativada
                    for (int i = 0; i < contas; i++) {
                        if (numeroConta[i] == numero) {
                            encontrada = i;
                            break;
                        }
                    }

                    if (encontrada != -1) {

                        if (contaAtiva[encontrada] == true) {
                            contaAtiva[encontrada] = false;
                            cout << "Conta desativada com sucesso!" << endl;
                        } else {
                            contaAtiva[encontrada] = true;
                            cout << "Conta ativada com sucesso!" << endl;
                        }

                    } else {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;


            case 6:
                cout << "Saindo..." << endl;
                break;


            default:
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 6);

    return 0;
}