/* #include "./alunos/alunos.c" */
#include "./cursos/cursos.c"

int main() {
    ListaMatricula *Lista = NULL;
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos)); 

    char NomeAluno[50];
    int NumeroMatricula;
    float notas[3];
    int contador = 0, SairCase = 0;
    int contador2 = 0, contador3, Vagas = 3;  //Vagas são as vagas de cada curso 

    int escolha = 0;

    char Nomealuno[50], Nomecurso[50];
    int matricula, codigo;

    char NomeCurso[50];
    int CodigoCurso;

    int MenuEscolha;

    do{
        system("cls");
        menu();
        printf("-> ");
        scanf("%d", &MenuEscolha);
        tratativa(MenuEscolha);
        LimparBuffer();

        switch(MenuEscolha) {
        case 1:
            system("cls");
            escolha = 0;
            while(escolha != 2) {
                system("cls");
                int Comparar = 0;
                printf("| 1.Criar Aluno | 2. Voltar ao Menu | -> ");
                scanf("%d", &escolha);
                tratativa(escolha);
                LimparBuffer();

                switch(escolha) {
                    case 1:
                        contador++;
                        printf("Informe o nome do aluno(a) %i: -> ", contador);
                        scanf(" %[^\n]", NomeAluno);
                        LimparBuffer();
                        FormatarString(NomeAluno);
                        getchar();
                        printf("Infome o numero de matricula do aluno(a) %i: -> ", contador);
                        scanf("%d", &NumeroMatricula);
                        tratativa(NumeroMatricula);
                        LimparBuffer();

                        Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);

                        while(Comparar == 1) {
                            system("cls");
                            Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);
                            if(Comparar == 1) {
                                printf("Informe o numero da matricula novamente: -> ");
                                scanf("%d", &NumeroMatricula);
                                tratativa(NumeroMatricula);
                                LimparBuffer();
                                Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);
                            }
                        }

                        for(int j = 0; j < 3; j++) {
                            printf("Digite a nota %i: -> ", j + 1);
                            scanf("%f", &notas[j]);
                            LimparBuffer();
                            
                        }

                        Alunos *VarAluno = Criar_Alunos(NomeAluno, NumeroMatricula, notas);

                        if(escolha == 1) {
                            Var_Alunos = (Alunos*)realloc(Var_Alunos, (contador + 2) * sizeof(Alunos));
                            if(Var_Alunos == NULL) {
                                printf("Erro ao realocar Var_Alunos \n");
                            }
                        }

                        Var_Alunos[contador - 1] = *VarAluno;
                        break;
                    }
                }
                break;
            case 2:  
                system("cls");
                escolha = 0;
                while(escolha != 2) { 
                    //system("cls");
                    int Comparar = 0;
                    printf("| 1.Criar Curso | 2.Voltar ao Menu | -> ");
                    scanf("%d", &escolha);
                    tratativa(escolha);
                    LimparBuffer();
                    
                    switch(escolha) {
                        case 1:
                            contador2++;
                            printf("\nInfome a disciplina: -> ");
                            scanf(" %[^\n]", NomeCurso);
                            LimparBuffer();
                            FormatarString(NomeCurso);
                            getchar();
                            printf("Informe o codigo do curso: -> ");
                            scanf("%d", &CodigoCurso);
                            tratativa(CodigoCurso);
                            LimparBuffer();
                            Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                            system("cls");
                            if(Comparar == 2) {
                                printf("Curso criado! \n\n");
                            }
                            while(Comparar == 1) {
                                system("cls");
                                Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                                if(Comparar == 1) {
                                    printf("Codigo ja existente! \n");
                                    printf("Informe o codigo do curso novamente: \n");
                                    scanf("%d", &CodigoCurso);
                                    LimparBuffer();
                                    Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                                } 
                                if(Comparar == 2) {
                                    printf("Curso criado! \n");
                                }
                            }
                            Cursos *VarCursos = Criar_Cursos(NomeCurso, CodigoCurso, Vagas);

                            if(escolha == 1) {
                                Var_Cursos = (Cursos*)realloc(Var_Cursos, (contador2 + 2) * sizeof(Cursos));
                                if(Var_Cursos == NULL) {
                                    printf("Realocacao de Var_Cursos falhou! \n");
                                    exit(1);
                                }
                            }

                            Var_Cursos[contador2 - 1] = *VarCursos;
                            break;
                        case 2:
                            break;  
                    }
                }
                break;
            case 3:
                escolha = 0;
                while(escolha != 2) {
                    //system("cls");
                    Imprimir_Cursos(Var_Cursos, contador2);
                    printf("\nLISTA DE ALUNOS: \n");
                    Imprimir_Alunos(Var_Alunos, contador);
                    if(contador == 0 || contador2 == 0) {
                        printf("\nDigite 2 para sair! -> \n");
                        scanf("%d", &escolha);
                        tratativa(escolha);
                        LimparBuffer();
                        if(escolha != 2) {
                            while(escolha != 2) {
                                printf("\nDigite 2 para sair! -> \n");
                                scanf("%d", &escolha);
                                tratativa(escolha);
                                LimparBuffer();
                            }
                        }
                    } else {
                        escolha = 0;
                        contador3 = contador;
                        printf("Informe | 1. MATRICULA DO ALUNO | 2. SAIR DA MATRICULA |: -> \n");
                        scanf("%d", &escolha);
                        tratativa(escolha);
                        LimparBuffer();

                        switch(escolha) {
                            case 1:
                                printf("Informe a matricula do aluno: -> ");
                                scanf("%d", &matricula);
                                LimparBuffer();
                                break;
                            case 2:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        } 
                        if(escolha == 2) {
                            break;
                        } else {
                            escolha = 0;
                        }
                        printf("Informe | 1.CODIGO | 2.SAIR DA MATRICULA |: -> ");
                        scanf("%d", &escolha);
                        tratativa(escolha);
                        LimparBuffer();
                        switch(escolha) {
                            case 1:
                                printf("Digite o codigo: -> ");
                                scanf("%d", &codigo);
                                tratativa(codigo);
                                LimparBuffer();
                                break;    
                            case 2:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        }
                        // Procura o aluno pelo número da matrícula e o curso pelo código
                        Alunos *alunoSelecionado = NULL;
                        Cursos *cursoSelecionado = NULL;

                        for (int i = 0; i < contador3; i++) {
                            if (Var_Alunos[i].numero_matricula == matricula) {
                                alunoSelecionado = &Var_Alunos[i];
                                break;
                            }
                        }

                        contador3 = contador2; // contador3 = contador2 para contador3 ter o numero total de disciplinas criadas

                        for (int i = 0; i < contador3; i++) {
                            if (Var_Cursos[i].codigo == codigo) {
                                cursoSelecionado = &Var_Cursos[i];
                                break;
                            }
                        }

                        if (alunoSelecionado != NULL && cursoSelecionado != NULL) {                            
                            // Matricular o aluno no curso
                            MatricularAlunoEmCurso(alunoSelecionado, cursoSelecionado, &Lista);
                        } else {
                            printf("\n===================================\n");
                            printf("Aluno ou curso nao encontrado.\n");
                            printf("=====================================\n");
                        }
                    } 
                } 
                break;
            case 4:
                system("cls");
                escolha = 0;
                char NomeAluno[30];
                int CodigoDisciplina;
                while(escolha != 2) {
                    ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                    printf("| 1.Excluir Matricula | 2. Voltar ao Menu | -> ");
                    scanf("%d", &escolha);
                    tratativa(escolha);
                    LimparBuffer();

                    switch(escolha) {
                        case 1:
                            system("cls");
                            if(Lista == NULL) {
                                printf("Nao ha nenhuma matricula! \n");
                                break;
                            } else {
                                ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                            }
                            printf("\nInforme o Nome do Aluno: -> ");
                            scanf(" %[^\n]", NomeAluno);
                            LimparBuffer();
                            FormatarString(NomeAluno);
                            getchar();
                            printf("Informe o Codigo do Curso: -> ");
                            scanf("%d", &CodigoDisciplina);
                            tratativa(CodigoDisciplina);
                            LimparBuffer();
                            ExcluirMatricula(&Lista, NomeAluno, Var_Cursos, CodigoDisciplina);
                        break;
                        case 2:
                            break;
                        default:
                            printf("Digite uma opcao valida! \n");
                    }
                }
                break;
            case 5:
                if(contador2 == 0) {
                    printf("\nNao ha nenhuma matricula! \n\n");
                }
                ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                printf("Digite 2 para sair -> ");
                scanf("%d", &SairCase);
                LimparBuffer();
                if(SairCase != 2) {
                    while(SairCase != 2) {
                        printf("Digite 2 para sair -> ");
                        scanf("%d", &SairCase);
                        tratativa(SairCase);
                        LimparBuffer();
                    }
                }
                break;
            case 6:
                system("cls");
                escolha = 0;
                char NomeCurso[30];
                while(escolha != 2) {
                    printf("| 1.Buscar Curso | 2. Voltar ao Menu | -> ");
                    scanf("%d", &escolha);
                    tratativa(escolha);
                    LimparBuffer();

                    switch(escolha) {
                        case 1:
                            system("cls");
                            printf("Informe o nome do curso: -> ");
                            scanf(" %[^\n]", NomeCurso);
                            LimparBuffer();
                            FormatarString(NomeCurso);
                            getchar();
                            BuscarCurso(Var_Cursos, NomeCurso, contador2);
                            break;
                        case 2:
                            break;
                        default:
                            system("cls");
                            printf("Digite uma opcao valida! \n\n");
                    }
                }
                break;
            case 7:
                system("cls");
                escolha = 0;
                int escolha2 = 0;
                SairCase = 0;
                char NomeAlunoEditar[30], NovoNomeAluno[30];
                int MatriculaAlunoEditar, NovaMatriculaAluno;
                float NotaEditar, NovaNota;
                while(escolha != 2) {
                    printf("\n| 1.Editar matricula | 2.Voltar ao Menu | -> ");
                    scanf("%d", &escolha);
                    tratativa(escolha);
                    LimparBuffer();
                    /* if(escolha == 2) {
                        break;
                    }  */

                    switch(escolha) {
                        case 1:
                            system("cls");
                            printf("===========================\n");
                            printf("|   1.Nome do Aluno      | \n");
                            printf("|   2.Matricula do Aluno | \n");
                            printf("|   3.Notas do Aluno     | \n");
                            printf("|   4.Voltar ao Menu     | \n");
                            printf("===========================\n");
                            printf("-> ");
                            scanf("%d", &escolha2);
                            tratativa(escolha2);
                            LimparBuffer();

                            switch(escolha2) {
                                case 1:
                                    if(Lista == NULL) {
                                        printf("Nao ha nenhum aluno cadastrado! \n");
                                        break;
                                    }
                                    ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                                    printf("Informe a matricula do aluno que deseja editar: -> ");
                                    scanf("%d", &MatriculaAlunoEditar);
                                    LimparBuffer();
                                    /* printf("\nInforme o nome do Aluno que deseja editar: -> ");
                                    scanf(" %[^\n]", NomeAlunoEditar); */
                                    LimparBuffer();
                                    getchar();
                                    printf("\nInforme o novo nome: -> ");
                                    scanf(" %[^\n]", NovoNomeAluno);

                                    LimparBuffer();

                                    FormatarString(NovoNomeAluno);

                                    EditarNomeAluno(&Lista, MatriculaAlunoEditar, NovoNomeAluno, Var_Alunos, contador);
                                    break;
                                case 2:
                                    if(Lista == NULL) {
                                        printf("Nao ha nenhum aluno cadastrado! \n");
                                        break;
                                    }
                                    ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                                    printf("Informe a matricula do Aluno que deseja editar: -> ");
                                    scanf("%d", &MatriculaAlunoEditar);
                                    tratativa(MatriculaAlunoEditar);
                                    LimparBuffer();
                                    printf("Informe a nova matricula do aluno: -> ");
                                    scanf("%d", &NovaMatriculaAluno);
                                    tratativa(NovaMatriculaAluno);
                                    LimparBuffer();
                                    EditarMatriculaAluno(&Lista, MatriculaAlunoEditar, NovaMatriculaAluno, Var_Alunos, contador);
                                    break;
                                case 3:
                                    if(Lista == NULL) {
                                        printf("Nao ha nenhum aluno cadastrado! \n");
                                        break;
                                    }
                                    ImprimirListaMatriculas(Lista, Var_Cursos, contador2);
                                    printf("Informe a matricula do aluno: -> ");
                                    scanf("%d", &MatriculaAlunoEditar);
                                    LimparBuffer();
                                    printf("Informe a Nota que voce deseja modificar: -> ");
                                    scanf("%f", &NotaEditar);
                                    LimparBuffer();
                                    printf("Informe a nova Nota: -> ");
                                    scanf("%f", &NovaNota);
                                    LimparBuffer();
                                    EditarNotaAluno(&Lista, NotaEditar, NovaNota, MatriculaAlunoEditar, Var_Alunos, contador);
                                    break;
                                case 4:
                                    escolha = 2;
                                    break;
                                default:
                                    printf("Digite uma opcao valida! \n"); 
                            }
                        case 2:
                            break;
                        default:
                            printf("Digite uma opcao valida! \n");
                    }
                }
                break;
            case 8: 
                SairCase = 0;
                VagasDisponiveis(Var_Cursos, contador2);
                while(SairCase != 2) {
                    printf("Digite 2 para sair! \n");
                    scanf("%d", &SairCase);
                    tratativa(SairCase);
                    LimparBuffer();
                }
                break;
            case 9:
                escolha = 0;
                int CodigoCurso;
                while(escolha != 2) {
                    printf("\n| 1.Consultar Quantitativo de Alunos no Curso | 2.Voltar ao Menu | -> ");
                    scanf("%d", &escolha);
                    tratativa(escolha);
                    LimparBuffer();

                    switch(escolha) {
                        case 1:
                            if(Lista == NULL) {
                                printf("Nao ha nenhum aluno cadastrado! \n");
                                break;
                            }
                            Imprimir_Cursos(Var_Cursos, contador2);
                            printf("\nInforme o codigo do curso: ");
                            scanf("%d", &CodigoCurso);
                            LimparBuffer();
                            QntAlunosCurso(&Lista, CodigoCurso);
                            break;
                        case 2:
                            break;
                        default:
                            printf("Digite uma opcao valida! \n");
                    }
                }
                break;
            case 10:
                break;
            default:
                printf("Voce digitou um opcao invalida! \n");
        }

    } while(MenuEscolha != 10);

    // Libera a memória alocada para alunos
    free(Var_Alunos);
    free(Var_Cursos);

    return 0;
}