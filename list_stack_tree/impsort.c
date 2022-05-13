void shellSort (tipoLista lst)
{
	int salto, flagTroca, i;
	
	if(lst.qtd > 0)
	{
		salto=lst.qtd/2;
		
		if(salto%2 == 0)
			salto--;
		
		flagTroca=1;
		
		while(flagTroca == 1 || salto != 1)
		{
			flagTroca=0;
			
			for(i=0; i < lst.qtd-salto; i++)
			{
				if(lst.qtd[i] > lst.vet[i+salto])
				{
					trocaValor(lst.vet[i], lst.vet[i+salto])
					flagTroca=1;
				}
			}
			salto = salto-2;
		}
}
tipoLista insereSort(tipoLista lst)
{
	int i;
	tipoLista lstOrd;
	
	if(lst.qtd > 0)
	{
		lstOrd.qtd = 0;
		for(i=0 ; i < lst.qtd; i++)
			insereOrdenado(lst.qtdOrd, lst.vet[i])
	}
	return lstOrd;
}
