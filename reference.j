.source                  reference.java
.class                   public reference
.super                   java/lang/Object


.method                  public <init>()V
   .limit stack          1
   .limit locals         1
   .line                 1
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   return                
.end method              

.method                  public static main([Ljava/lang/String;)V
   .limit stack          0
   .limit locals         1
   .line                 5
   invokestatic          reference/main()V
   .line                 6
   return                
.end method              

.method                  static main()V
   .limit stack          2
   .limit locals         0
   .line                 20
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iconst_1              
   invokevirtual         java/io/PrintStream/print(Z)V
   .line                 21
   return                
.end method              

