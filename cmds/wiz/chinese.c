inherit F_CLEAN_UP;
int help();
int main(object me, string arg)
{
	string key, chinz;

	if( !arg || arg=="" )
		return help();
	if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		CHINESE_D->add_translate(key, chinz);
		write( "���Ӷ��գ�"+key + " == " + chinz + "\nOk.\n");
		return 1;
	}
//else������jackyboy@cctx����
	else
		if(arg!=CHINESE_D->chinese(arg))
		{
			write("ɾ�����գ�"+arg+"<==>"+CHINESE_D->chinese(arg)+"\n");
			CHINESE_D->remove_translate(arg);
			return 1;
		}
		else
			return help();
}			

int help()
{
	write ( @HELP
���Ӷ��գ�chinese <Ӣ��>==<����>
ɾ�����գ�chinese <Ӣ��>
HELP
	);
	return 1 ;
}
