import Data.List.Split

main :: IO ()
main = do
  putStrLn "Start!"
  moves <- getLine
  print $ splitOn ", " moves
      
