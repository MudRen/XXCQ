inherit F_CLEAN_UP;
int main(object me,string arg)
{
	string chn;
	if(!arg)
		return notify_fail("��Ҫ���ϲ�����lock [off|on] channel_id\n");
	if(sscanf(arg,"off %s",chn))
		(CHANNEL_D->do_lock(chn))?write("Lock "+chn+" ok.\n"):write("Lock "+chn+" fail.\n");
	else
	if(sscanf(arg,"on %s",chn))
		(CHANNEL_D->do_unlock(chn))?write("Unlock "+chn+" ok.\n"):write("Unlock "+chn+" fail.\n");
	else
		return notify_fail("��������lock [off|on] channel_id\n");
	return 1;
}
