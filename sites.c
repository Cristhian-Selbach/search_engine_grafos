#include "sites.h"

Site sites[MAX_SITES] = {
    {"computadores.com", 
     "Tudo sobre Computadores", 
     "Bem-vindo ao maior portal de tecnologia da América Latina! Aqui você encontra:\n\n"
     "- Guias completos para montagem e manutenção de computadores\n"
     "- Análises detalhadas dos melhores componentes de hardware do mercado\n"
     "- Tutoriais de configuração e otimização de sistemas\n"
     "- Notícias diárias sobre lançamentos e inovações tecnológicas\n"
     "- Fóruns de discussão com especialistas e entusiastas\n\n"
     "Nossa equipe de engenheiros e técnicos certificados está sempre atualizando o conteúdo "
     "para trazer as informações mais relevantes e precisas sobre o mundo da computação."},
     
    {"matematica.com", 
     "Matemática para Todos", 
     "Portal educativo dedicado ao ensino da matemática de forma acessível e divertida!\n\n"
     "Recursos disponíveis:\n"
     "- Videoaulas desde aritmética básica até cálculo avançado\n"
     "- Exercícios interativos com correção automática\n"
     "- Material preparatório para ENEM e vestibulares\n"
     "- Seções especiais para professores com planos de aula\n"
     "- Desafios semanais com premiação para os melhores\n\n"
     "Nosso método de ensino foi desenvolvido por doutores em educação matemática e já ajudou "
     "mais de 2 milhões de estudantes a superarem suas dificuldades."},
     
    {"calculodiferencial.com", 
     "Cálculo Diferencial e Integral", 
     "O centro de referência para estudantes de engenharia e ciências exatas!\n\n"
     "Conteúdo completo que cobre:\n"
     "- Limites e continuidade de funções\n"
     "- Derivadas e suas aplicações\n"
     "- Integrais definidas e indefinidas\n"
     "- Séries e sequências infinitas\n"
     "- Equações diferenciais ordinárias\n\n"
     "Além da teoria, oferecemos:\n"
     "- Mais de 500 exercícios resolvidos passo a passo\n"
     "- Calculadoras gráficas online\n"
     "- Simuladores de problemas de física e engenharia\n"
     "- Aulas ao vivo semanais com professores universitários"},
     
    {"fisica.com", 
     "Física Moderna e Clássica", 
     "Explore os mistérios do universo através da física!\n\n"
     "Nossos conteúdos incluem:\n"
     "- Mecânica clássica (Newton, Lagrange, Hamilton)\n"
     "- Eletromagnetismo e circuitos elétricos\n"
     "- Termodinâmica e física estatística\n"
     "- Física quântica e teoria da relatividade\n"
     "- Astrofísica e cosmologia\n\n"
     "Recursos exclusivos:\n"
     "- Laboratório virtual com simulações realistas\n"
     "- Documentários exclusivos sobre grandes físicos\n"
     "- Podcast semanal 'Física no Cotidiano'\n"
     "- Banco de dados com todos os prêmios Nobel de Física\n"
     "- Programa de mentoria para jovens cientistas"},
     
    {"programacao.com", 
     "Aprenda a Programar do Zero", 
     "Sua jornada no mundo da programação começa aqui!\n\n"
     "Cursos completos disponíveis:\n"
     "- Fundamentos de lógica de programação\n"
     "- Python para ciência de dados\n"
     "- Desenvolvimento Web (HTML, CSS, JavaScript)\n"
     "- Mobile (Android, iOS, Flutter)\n"
     "- Banco de dados e back-end\n\n"
     "Diferenciais da nossa plataforma:\n"
     "- Ambiente de desenvolvimento integrado no navegador\n"
     "- Certificação reconhecida pelo mercado\n"
     "- Projetos reais para portfolio\n"
     "- Comunidade ativa com mais de 500 mil devs\n"
     "- Feira de recrutamento mensal com grandes empresas"},
     
    {"historia.com", 
     "História Mundial em Detalhes", 
     "Uma viagem fascinante pela história da humanidade!\n\n"
     "Explore nossas seções:\n"
     "- História antiga: Egito, Grécia, Roma\n"
     "- Idade Média e Renascimento\n"
     "- Revoluções e formação dos estados nacionais\n"
     "- Guerras mundiais e conflitos contemporâneos\n"
     "- História da América Latina\n\n"
     "Conteúdo multimídia exclusivo:\n"
     "- Reconstituições em 3D de cidades históricas\n"
     "- Linhas do tempo interativas\n"
     "- Documentários produzidos por historiadores\n"
     "- Acervo digital com mais de 10 mil documentos\n"
     "- Visitas virtuais a museus e sítios arqueológicos"},
     
    {"eletronica.com", 
     "Eletrônica para Maker e Profissionais", 
     "Do básico ao avançado em circuitos eletrônicos!\n\n"
     "Aprenda sobre:\n"
     "- Componentes eletrônicos e suas funções\n"
     "- Projeto de circuitos analógicos e digitais\n"
     "- Microcontroladores (Arduino, ESP, Raspberry Pi)\n"
     "- IoT e automação residencial\n"
     "- PCB design e fabricação caseira\n\n"
     "Na nossa plataforma você encontra:\n"
     "- Kits de componentes para montagem em casa\n"
     "- Fórum para tirar dúvidas com especialistas\n"
     "- Desafios mensais com prêmios\n"
     "- Galeria de projetos compartilhados\n"
     "- Tutoriais para reparo de equipamentos"},
     
    {"ciencia.com", 
     "Ciência e Tecnologia Atual", 
     "As últimas descobertas científicas em primeira mão!\n\n"
     "Cobertura em todas as áreas:\n"
     "- Biotecnologia e genética\n"
     "- Inteligência artificial e robótica\n"
     "- Energias renováveis e sustentabilidade\n"
     "- Nanotecnologia e novos materiais\n"
     "- Exploração espacial e astronomia\n\n"
     "Destaques do portal:\n"
     "- Boletim diário com as principais pesquisas\n"
     "- Entrevistas exclusivas com cientistas\n"
     "- Explicações descomplicadas de artigos acadêmicos\n"
     "- Agenda de eventos científicos\n"
     "- Programa de estágios em centros de pesquisa"},
     
    {"filmes.com", 
     "Cinema e Cultura Pop", 
     "O universo do cinema como você nunca viu!\n\n"
     "Nossos conteúdos incluem:\n"
     "- Críticas de filmes atuais e clássicos\n"
     "- Bastidores da produção cinematográfica\n"
     "- Análises de trilhas sonoras e fotografia\n"
     "- Documentários sobre história do cinema\n"
     "- Entrevistas com diretores e atores\n\n"
     "Vantagens para assinantes:\n"
     "- Guia semanal do que vale a pena assistir\n"
     "- Listas temáticas curadas por especialistas\n"
     "- Clube do filme com discussões online\n"
     "- Descontos em serviços de streaming\n"
     "- Sorteios de ingressos e produtos exclusivos"},
     
    {"musica.com", 
     "Música em Todos os Sentidos", 
     "Aprofunde seu conhecimento e amor pela música!\n\n"
     "Explore nossos recursos:\n"
     "- Cursos de teoria musical e harmonia\n"
     "- História dos gêneros e movimentos musicais\n"
     "- Técnicas de produção musical e mixagem\n"
     "- Guia de equipamentos e instrumentos\n"
     "- Análise de obras e compositores\n\n"
     "Funcionalidades exclusivas:\n"
     "- Player interativo para estudo de músicas\n"
     "- Metrônomo e afinador online\n"
     "- Banco de partituras e tablaturas\n"
     "- Comunidade para colaboração entre músicos\n"
     "- Agenda de shows e festivais mundiais"}
};

int totalSites = 10;
