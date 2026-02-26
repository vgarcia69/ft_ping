# ft_ping

    Use
        int inet_pton(int af, const char *restrict src, void *restrict dst);
    To convert a string to binary network address

    Use
     int getaddrinfo(const char *restrict node,
                       const char *restrict service,
                       const struct addrinfo *restrict hints,
                       struct addrinfo **restrict res);
    To convert a domain name to an ip address


    struct icmphdr


    Dans l'idee on va parse les args, si - flag, getaddrinfo
    
    On setup une socket pour le ICMP protocole

    puis en boucle:
        construction packet icmp (header et checksum)
        sendto, 
        recvfrom,
        calcul de temps diff, etc,
        print

    au ctrl+c, sigint
    
    print stats de toute les infos




    pour les struct, stocker les stats ensemble
    
    name a stocker pour le ctrl C
    ip dans la boucle

    struct qui stocke les flags, le sockfd et la sockaddr