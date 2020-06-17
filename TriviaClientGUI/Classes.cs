using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace TriviaClientGUI
{
    public class StatusResponse { public int Status { get; set; } }
    public class Statistics { public int Status { get; set; } public HighScore[] HighScores { get; set; } public UserStatistics UserStatistics { get; set; } }
    public class HighScore { public string Name { get; set; } public int NumOfCorrectAnswers { get; set; } }
    public class UserStatistics { public float AverageAnswerTime { get; set; } public int CorrectAnswers { get; set; } public int PlayerGames { get; set; } public int WrongAnswers { get; set; } }
    public class GetRooms { public Room[] Rooms { get; set; } public int Status { get; set; } }
    public class Room { public string CreatedBy { get; set; } public string RoomName { get; set; } public int RoomId { get; set; } }
    public class GetPlayersInRoom { public Player[] PlayersInRoom { get; set; } }
    public class Player { public string PlayerName { get; set; } }
    public partial class GetRoomState { public int AnswerTimeout { get; set; } public bool HasGameBegun { get; set; } public Player[] PlayersInRoom { get; set; } public int QuestionCount { get; set; } public int Status { get; set; } }
    public partial class GetQuestion { public PossibleAnswer[] PossibleAnswers { get; set; } public string Question { get; set; } public int Status { get; set; } }
    public partial class PossibleAnswer { public string Answer { get; set; } }
    public class SubmitAnswer { public int Status { get; set; } public bool IsCorrectAnswer { get; set; } }
    public partial class GetGameResults { public Result[] Results { get; set; } public int Status { get; set; } }
    public partial class Result { public double AverageAnswerTime { get; set; } public int CorrectAnswerCount { get; set; } public string Username { get; set; } public int WrongAnswerCount { get; set; } }

    class Client
    {
        static NetworkStream clientStream;

        static public string SendPayload(char code, string payload)
        {
            if (clientStream == null) // connect only if not already connected
            {
                try
                {
                    TcpClient client = new TcpClient();
                    IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1234);
                    client.Connect(serverEndPoint);
                    clientStream = client.GetStream();

                    //////////////// get server public key 
                    //////////////byte[] buffer = new byte[4096];
                    //////////////clientStream.Read(buffer, 0, 4096);
                    //////////////// send public key

                    ////////////////Create a UnicodeEncoder to convert between byte array and string.
                    //////////////UnicodeEncoding ByteConverter = new UnicodeEncoding();

                    ////////////////Create byte arrays to hold original, encrypted, and decrypted data.
                    //////////////byte[] dataToEncrypt = ByteConverter.GetBytes("Data to Encrypt");
                    //////////////byte[] encryptedData;
                    //////////////byte[] decryptedData;

                    ////////////////Create a new instance of RSACryptoServiceProvider to generate
                    ////////////////public and private key data.
                    //////////////using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider())
                    //////////////{
                    //////////////    encryptedData = RSAEncrypt(dataToEncrypt, RSA.ExportParameters(false), false);

                    //////////////    decryptedData = RSADecrypt(encryptedData, RSA.ExportParameters(true), false);
                    //////////////}

                }
                catch (Exception)
                {
                    clientStream = null;
                    MessageBox.Show("The server is dead", "Error Detected");
                    return "server is dead";
                }
            }
            try
            {
                payload = code + payload.Length.ToString("D5") + payload;
                byte[] buffer = new ASCIIEncoding().GetBytes(payload);
                clientStream.Write(buffer, 0, buffer.Length);
                clientStream.Flush();
                buffer = new byte[4096];
                clientStream.Read(buffer, 0, 4096);
                string deserializeBuffer = Encoding.UTF8.GetString(buffer);
                return deserializeBuffer.Substring(5, Int32.Parse(deserializeBuffer.Substring(1, 4)) - 1);
            }
            catch(Exception)
            {
                clientStream = null;
                System.Threading.Tasks.Task.Run( () => { MessageBox.Show("The server has died, you have been loged out", "Error Detected"); });
                return "server has died";
            }
        }

        ////////////public static byte[] RSAEncrypt(byte[] DataToEncrypt, RSAParameters RSAKeyInfo, bool DoOAEPPadding)
        ////////////{
        ////////////    try
        ////////////    {
        ////////////        byte[] encryptedData;
        ////////////        //Create a new instance of RSACryptoServiceProvider.
        ////////////        using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider())
        ////////////        {

        ////////////            //Import the RSA Key information. This only needs
        ////////////            //toinclude the public key information.
        ////////////            RSA.ImportParameters(RSAKeyInfo);

        ////////////            //Encrypt the passed byte array and specify OAEP padding.  
        ////////////            //OAEP padding is only available on Microsoft Windows XP or
        ////////////            //later.  
        ////////////            encryptedData = RSA.Encrypt(DataToEncrypt, DoOAEPPadding);
        ////////////        }
        ////////////        return encryptedData;
        ////////////    }
        ////////////    //Catch and display a CryptographicException  
        ////////////    //to the console.
        ////////////    catch (CryptographicException e)
        ////////////    {
        ////////////        Console.WriteLine(e.Message);

        ////////////        return null;
        ////////////    }
        ////////////}

        ////////////public static byte[] RSADecrypt(byte[] DataToDecrypt, RSAParameters RSAKeyInfo, bool DoOAEPPadding)
        ////////////{
        ////////////    try
        ////////////    {
        ////////////        byte[] decryptedData;
        ////////////        //Create a new instance of RSACryptoServiceProvider.
        ////////////        using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider())
        ////////////        {
        ////////////            //Import the RSA Key information. This needs
        ////////////            //to include the private key information.
        ////////////            RSA.ImportParameters(RSAKeyInfo);

        ////////////            //Decrypt the passed byte array and specify OAEP padding.  
        ////////////            //OAEP padding is only available on Microsoft Windows XP or
        ////////////            //later.  
        ////////////            decryptedData = RSA.Decrypt(DataToDecrypt, DoOAEPPadding);
        ////////////        }
        ////////////        return decryptedData;
        ////////////    }
        ////////////    //Catch and display a CryptographicException  
        ////////////    //to the console.
        ////////////    catch (CryptographicException e)
        ////////////    {
        ////////////        Console.WriteLine(e.ToString());

        ////////////        return null;
        ////////////    }
        ////////////}
    }
}
