// oneowner.c
// the function check_owner() should be put in init() of a given object.
// it will ensure that only the first user who get this 
// object can keep it, otherwise it will disappear automatically.

// mon 2/7/98

private static string obj_owner=0;
nomask void self_destroy();

void check_owner()
{
  object env=environment();

  if(!clonep()) return;

  if(!env) {
    call_out("self_destroy",1);
    return;
  }
    
  //for room or other containers.  
  if(!env->is_character()) {
    if(obj_owner) call_out("self_destroy",5+random(5));
    return;
  }  
  
  //for npc.
  if(!userp(env)) {
    if(obj_owner)
      call_out("self_destroy",5+random(5));
    return; 
    //allow NPC to carry it if no one has own it.
  }  
     
  //following is for user.   
  if(!obj_owner)
    obj_owner=env->query("id");
  else {
    if(obj_owner!=env->query("id"))
      call_out("self_destroy",2+random(5));
    else
      remove_call_out("self_destroy");  
      //one can still pick it up if loses it for a short while.
  }
}

void self_destroy()
{
  object env=environment();

  if(env) {
    if(env->is_character()) { 
      tell_object(env,"��ͻȻ�������˾������������Ȼת���Ǹ�������һ������æ�����ˣ�\n");
      tell_object(env,"��Ͻ�������ϵĶ���������"+this_object()->query("name")+"��Ȼ������͵���ˣ�����ֻ��ϧû�������˵����ӡ�\n");  
    } else {
      tell_object(env,"�и���Ӱ���˳������������˲�ע�⣬͵͵�ļ���"+this_object()->query("name")+"�����ˡ�\n");
    }
  }
  
  destruct(this_object());
}
