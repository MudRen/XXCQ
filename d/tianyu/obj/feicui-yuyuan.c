//Obj  �����Բ
//By godzilla 11.18.99

inherit ITEM;

inherit F_FOOD;


void create()

{
        set_name("��Բ��", ({"yuyuanzi"}));
          set_weight(200);
        
          if (clonep())

                set_default_object(__FILE__);

          else {

                set("long", "һ��������Ŀɿڵ���Բ��\n");

                set("unit", "��");

                set("value", 150);

                set("food_remaining", 4);

                set("food_supply", 40);

        }

}
