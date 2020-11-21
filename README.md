
<!-- README.md is generated from README.Rmd. Please edit that file -->

## Configuração inicial

#### Passo 1: Instalar pacotes

``` r
install.packages("remotes")

# instalar pacote da Curso-R
remotes::install_github("curso-r/CursoR")
```

#### Passo 2: Criar um projeto do RStudio

Faça um projeto do RStudio para usar durante todo o curso e em seguida
abra-o.

``` r
install.packages("usethis")
usethis::create_project("caminho_ate_o_projeto/nome_do_projeto")
```

#### Passo 3: Baixar o material

Certifique que você está dentro do projeto criado no passo 2 e rode o
código abaixo.

**Observação**: Assim que rodar o código abaixo, o programa vai pedir
uma escolha de opções. Escolha o número correspondente ao curso de Rcpp!

``` r
# Baixar ou atualizar material do curso
CursoR::atualizar_material()
```

## Slides

| Slide             | Link                                                      | Link em PDF                                                                |
|:------------------|:----------------------------------------------------------|:---------------------------------------------------------------------------|
| slides/index.html | <https://curso-r.github.io/202011-rcpp/slides/index.html> | <a href='https://curso-r.github.io/202011-rcpp/slides/index.pdf'> PDF </a> |

## Scripts usados em aula

| script                    | link                                                                       |
|:--------------------------|:---------------------------------------------------------------------------|
| 00-hello-world.cpp        | <https://curso-r.github.io/202011-rcpp/exemplos/00-hello-world.cpp>        |
| 01-primeira-funcao.cpp    | <https://curso-r.github.io/202011-rcpp/exemplos/01-primeira-funcao.cpp>    |
| 02-vetores.cpp            | <https://curso-r.github.io/202011-rcpp/exemplos/02-vetores.cpp>            |
| 03-na-nan.cpp             | <https://curso-r.github.io/202011-rcpp/exemplos/03-na-nan.cpp>             |
| 04-if-else.cpp            | <https://curso-r.github.io/202011-rcpp/exemplos/04-if-else.cpp>            |
| 05-data-frames.cpp        | <https://curso-r.github.io/202011-rcpp/exemplos/05-data-frames.cpp>        |
| 06-armadillo.cpp          | <https://curso-r.github.io/202011-rcpp/exemplos/06-armadillo.cpp>          |
| 07-chamar-funcao-do-r.cpp | <https://curso-r.github.io/202011-rcpp/exemplos/07-chamar-funcao-do-r.cpp> |
| 08-escapar.cpp            | <https://curso-r.github.io/202011-rcpp/exemplos/08-escapar.cpp>            |
